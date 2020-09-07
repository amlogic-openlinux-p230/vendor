#define _BSD_SOURCE /* for endian.h */
#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <asm/byteorder.h>
#include <linux/usb/functionfs.h>

#include "zgadget.h"
#include "trace.h"

#define cpu_to_le16(x)  htole16(x)
#define cpu_to_le32(x)  htole32(x)
#define le32_to_cpu(x)  le32toh(x)
#define le16_to_cpu(x)  le16toh(x)

/******************** Descriptors and Strings *******************************/
static const struct {
    struct usb_functionfs_descs_head header;
    struct {
        struct usb_interface_descriptor intf;
        struct usb_endpoint_descriptor_no_audio sink;
#if 0
        struct usb_endpoint_descriptor_no_audio source;
#endif
    } __attribute__((packed)) fs_descs, hs_descs;
} __attribute__((packed)) descriptors = {
    .header = {
        .magic = cpu_to_le32(FUNCTIONFS_DESCRIPTORS_MAGIC),
        .length = cpu_to_le32(sizeof descriptors),
        .fs_count = cpu_to_le32(2),
        .hs_count = cpu_to_le32(2),
    },
    .fs_descs = {
        .intf = {
            .bLength = sizeof descriptors.fs_descs.intf,
            .bDescriptorType = USB_DT_INTERFACE,
            .bNumEndpoints = 1,
            .bInterfaceClass = USB_CLASS_VENDOR_SPEC,
            .iInterface = 1,
        },
        .sink = {
            .bLength = sizeof descriptors.fs_descs.sink,
            .bDescriptorType = USB_DT_ENDPOINT,
            .bEndpointAddress = 1 | USB_DIR_IN,
            .bmAttributes = USB_ENDPOINT_XFER_BULK,
            /* .wMaxPacketSize = autoconfiguration (kernel) */
        },
#if 0
        .source = {
            .bLength = sizeof descriptors.fs_descs.source,
            .bDescriptorType = USB_DT_ENDPOINT,
            .bEndpointAddress = 2 | USB_DIR_OUT,
            .bmAttributes = USB_ENDPOINT_XFER_BULK,
            /* .wMaxPacketSize = autoconfiguration (kernel) */
        },
#endif
    },
    .hs_descs = {
        .intf = {
            .bLength = sizeof descriptors.fs_descs.intf,
            .bDescriptorType = USB_DT_INTERFACE,
            .bNumEndpoints = 1,
            .bInterfaceClass = USB_CLASS_VENDOR_SPEC,
            .iInterface = 1,
        },
        .sink = {
            .bLength = sizeof descriptors.hs_descs.sink,
            .bDescriptorType = USB_DT_ENDPOINT,
            .bEndpointAddress = 1 | USB_DIR_IN,
            .bmAttributes = USB_ENDPOINT_XFER_BULK,
            .wMaxPacketSize = cpu_to_le16(512),
        },
#if 0
        .source = {
            .bLength = sizeof descriptors.hs_descs.source,
            .bDescriptorType = USB_DT_ENDPOINT,
            .bEndpointAddress = 2 | USB_DIR_OUT,
            .bmAttributes = USB_ENDPOINT_XFER_BULK,
            .wMaxPacketSize = cpu_to_le16(512),
            .bInterval = 1, /* NAK every 1 uframe */
        },
#endif
    },
};

#define STR_INTERFACE_ "zProxy"
static const struct {
    struct usb_functionfs_strings_head header;
    struct {
        __le16 code;
        const char str1[sizeof STR_INTERFACE_];
    } __attribute__((packed)) lang0;
} __attribute__((packed)) strings = {
    .header = {
        .magic = cpu_to_le32(FUNCTIONFS_STRINGS_MAGIC),
        .length = cpu_to_le32(sizeof strings),
        .str_count = cpu_to_le32(1),
        .lang_count = cpu_to_le32(1),
    },
    .lang0 = {
        cpu_to_le16(0x0409), /* en-us */
        STR_INTERFACE_,
    },
};

struct thread {
    const char *filename;
    size_t buf_size;
    ssize_t (*in)(struct thread *, void *, size_t);
    ssize_t (*out)(struct thread *, const void *, size_t);
    int fd;
    pthread_t id;
    void *buf;
    ssize_t status;
    zgadget_t *z;
    volatile int cancel;
};

struct zgadget_s {
    zg_ep0_callback ep0;
    zg_out_callback out;
    void *that;
    struct thread threads[2]; // 0-control ep, 1-ep1-IN
    int pipefd[2];
    zpio_t *z0;
    zpio_t *z1;
};

static ssize_t read_wrap(struct thread *t, void *buf, size_t nbytes);
static ssize_t write_wrap(struct thread *t, const void *buf, size_t nbytes);
static ssize_t ep0_consume(struct thread *t, const void *buf, size_t nbytes);
static ssize_t fill_in_buf(struct thread *t, void *buf, size_t nbytes);
#if 0
static ssize_t empty_out_buf(struct thread *t, const void *buf, size_t nbytes);
#endif

static void init_thread(zgadget_t *z, struct thread *t)
{
    t->z = z;
    t->buf = malloc(t->buf_size);
    die_on(!t->buf, "malloc");
    t->fd = open(t->filename, O_RDWR);
    die_on(t->fd < 0, "init_thread(%s): %d", t->filename, errno);
}

static void cleanup_thread(void *arg)
{
    struct thread *t = arg;
    int ret, fd;
    fd = t->fd;
    if (t->fd < 0)
        return;
    t->fd = -1;
    /* test the FIFO ioctls (non-ep0 code paths) */
    if (t != t->z->threads) {
        ret = ioctl(fd, FUNCTIONFS_FIFO_STATUS);
        if (ret < 0) {
            /* ENODEV reported after disconnect */
            if (errno != ENODEV)
                err("%s: get fifo status", t->filename);
        } else if (ret) {
            warn("%s: unclaimed = %d\n", t->filename, ret);
            if (ioctl(fd, FUNCTIONFS_FIFO_FLUSH) < 0)
                err("%s: fifo flush", t->filename);
        }
    }
    if (close(fd) < 0)
        err("%s: close", t->filename);
    free(t->buf);
    t->buf = NULL;
    info("%s: clean\n", t->filename);
}

static void *start_thread_helper(void *arg)
{
    const char *op;
    struct thread *t = arg;
    ssize_t ret;
    info("%s: starts\n", t->filename);
    pthread_cleanup_push(cleanup_thread, arg);
    for (;;) {
        if (t->cancel)
            break;
        ret = t->in(t, t->buf, t->buf_size);
        if (ret > 0) {
            ret = t->out(t, t->buf, ret);
            op = "write";
        } else {
            op = "read";
        }
        if (ret > 0) {
            /* nop */
        } else if (ret == 0) {
//            debug("%s: %s: EOF", t->filename, op);
        } else if (errno == EINTR || errno == EAGAIN) {
            debug("%s: %s", t->filename, op);
        } else {
            warn("%s: %s errno=%d", t->filename, op, errno);
            break;
        }
    }
    pthread_cleanup_pop(1);
    t->status = ret;
    info("%s: ends\n", t->filename);
    return NULL;
}

static void start_thread(struct thread *t)
{
    debug("%s: starting\n", t->filename);
    die_on(pthread_create(&t->id, NULL, start_thread_helper, t) < 0,
            "pthread_create(%s)", t->filename);
}

static void join_thread(struct thread *t)
{
    int ret = pthread_join(t->id, NULL);
    if (ret < 0)
        err("%s: joining thread", t->filename);
    else
        debug("%s: joined\n", t->filename);
}

static void cancel_thread(struct thread *t)
{
    t->cancel = 1;
}

static ssize_t read_wrap(struct thread *t, void *buf, size_t nbytes)
{
    return read(t->fd, buf, nbytes);
}

static ssize_t write_wrap(struct thread *t, const void *buf, size_t nbytes)
{
    ssize_t r;
    zpio_set(t->z->z1, 1);
    r = write(t->fd, buf, nbytes);
    zpio_set(t->z->z1, 0);
    return r;
}

static ssize_t fill_in_buf(struct thread *t, void *buf, size_t nbytes)
{
    ssize_t r;
    zpio_set(t->z->z0, 1);
    r = read(t->z->pipefd[0], buf, nbytes);
    zpio_set(t->z->z0, 0);
    return r;
}

#if 0
static ssize_t empty_out_buf(struct thread *t, const void *buf, size_t nbytes)
{
    return t->z->out(t->z->that, buf, nbytes);
}
#endif

static void handle_setup(zgadget_t *z, const struct usb_ctrlrequest *setup)
{
    int r;
    static char buf[64]; // control transfers are 64 bytes max
//    memset(buf, 0, sizeof(buf));

//    info("handle_setup: %02X.%02X value=%04X index=%04X length=%04X",setup->bRequestType, setup->bRequest,
//        setup->wValue, setup->wIndex, setup->wLength);

// REVIEW: how can we handle IO errors here?
    if ((setup->bRequestType & 0x80) == 0 && setup->wLength > 0) {
        r = read(z->threads[0].fd, buf, setup->wLength);
    }
//    if (setup->bRequestType == 0x40 && setup->bRequest == 0x11 && setup->wLength >= 8) { // MCU SET, only used for flash write op
//        info("SETUP 40.11: r=%d %04X %04X %04X [%02X.%02X.%02X.%02X.%02X.%02X.%02X.%02X] ", r, setup->wValue, setup->wIndex, setup->wLength,
//             buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
//    }
    r = z->ep0(z->that, setup->bRequestType, setup->bRequest,
            le16_to_cpu(setup->wValue), le16_to_cpu(setup->wIndex),
            le16_to_cpu(setup->wLength), (byte *)buf);
    if (r > 0) {
        r = write(z->threads[0].fd, buf, r);
//        if (setup->bRequestType == 0xC0 && setup->bRequest == 0x11 && setup->wLength >= 8) { // MCU GET, flash read
//            info("SETUP C0.11: r=%d %04X %04X %04X [%02X.%02X.%02X.%02X.%02X.%02X.%02X.%02X] ", r, setup->wValue, setup->wIndex, setup->wLength,
//                 buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
//        }
    }
}

static ssize_t
ep0_consume(struct thread *t0, const void *buf, size_t nbytes)
{
    static const char *const names[] = {
        [FUNCTIONFS_BIND] = "BIND",
        [FUNCTIONFS_UNBIND] = "UNBIND",
        [FUNCTIONFS_ENABLE] = "ENABLE",
        [FUNCTIONFS_DISABLE] = "DISABLE",
        [FUNCTIONFS_SETUP] = "SETUP",
        [FUNCTIONFS_SUSPEND] = "SUSPEND",
        [FUNCTIONFS_RESUME] = "RESUME",
    };
    const struct usb_functionfs_event *event = buf;
    size_t n;
    for (n = nbytes / sizeof *event; n; --n, ++event)
        switch (event->type) {
            case FUNCTIONFS_BIND:
            case FUNCTIONFS_UNBIND:
            case FUNCTIONFS_ENABLE:
            case FUNCTIONFS_DISABLE:
            case FUNCTIONFS_SETUP:
            case FUNCTIONFS_SUSPEND:
            case FUNCTIONFS_RESUME:
                if (event->type == FUNCTIONFS_SETUP)
                    handle_setup(t0->z, &event->u.setup);
                else {
                    info("Event %s\n", names[event->type]);
                }
                break;
            default:
                info("Event %03u (unknown)\n", event->type);
                break;
        }
    return nbytes;
}
static void ep0_init(struct thread *t)
{
    ssize_t ret;
    info("%s: writing descriptors\n", t->filename);
    ret = write(t->fd, &descriptors, sizeof descriptors);
    die_on(ret < 0, "%s: write: descriptors error=%d", t->filename, errno);
    info("%s: writing strings\n", t->filename);
    ret = write(t->fd, &strings, sizeof strings);
    die_on(ret < 0, "%s: write: strings error=%d", t->filename, errno);
}

int zg_open(zgadget_t **pz, zg_ep0_callback ep0, zg_out_callback out, void *that, zpio_t *z0, zpio_t* z1) {
    unsigned u;
    zgadget_t *z = (zgadget_t *)malloc(sizeof(zgadget_t));
    memset(z, 0, sizeof(zgadget_t));
    z->ep0 = ep0;
    z->out = out;
    z->that = that;
    z->z0 = z0;
    z->z1 = z1;

    z->threads[0].filename = "/dev/usb-ffs/zproxy/ep0";
    z->threads[0].buf_size = 4 * sizeof(struct usb_functionfs_event);
    z->threads[0].in = read_wrap;
    z->threads[0].out = ep0_consume;

    z->threads[1].filename = "/dev/usb-ffs/zproxy/ep1";
    z->threads[1].buf_size = 64 * 1024;
    z->threads[1].in = fill_in_buf;
    z->threads[1].out = write_wrap;
#if 0
    z->threads[2].filename = "/dev/usb-ffs/zproxy/ep2";
    z->threads[2].buf_size = 8 * 1024;
    z->threads[2].in = read_wrap;
    z->threads[2].out = empty_out_buf;
#endif
    die_on(pipe(z->pipefd) == -1, "pipe(pipefd)");
    int r = fcntl(z->pipefd[0], F_SETPIPE_SZ, 1024*1024); // 1MB; default is 16 pages = 64KB
    if (r < 0) { info("fcntl(F_SETPIPE_SZ): %d\n", errno); }
    init_thread(z, &z->threads[0]);
    ep0_init(&z->threads[0]);
    for (u = 1; u < sizeof(z->threads) / sizeof(z->threads[0]); ++u)
        init_thread(z, &z->threads[u]);
    for (u = 1; u < sizeof(z->threads) / sizeof(z->threads[0]); ++u)
        start_thread(&z->threads[u]);
    start_thread(&z->threads[0]);
    *pz = z;
    return 0;
}

int zg_close(zgadget_t *z) {
    unsigned u;
    for (u = 0; u < sizeof(z->threads) / sizeof(z->threads[0]); ++u)
        cancel_thread(&z->threads[u]);
    for (u = 0; u < sizeof(z->threads) / sizeof(z->threads[0]); ++u)
        join_thread(&z->threads[u]);
    close(z->pipefd[0]);
    close(z->pipefd[1]);
    return 0;
}

ssize_t zg_write(zgadget_t *z, const void *buf, int bytes) {
    return write(z->pipefd[1], buf, bytes);
}
