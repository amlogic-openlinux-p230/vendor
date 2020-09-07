#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

#include "trace.h"
#include "reishi.h"
#include "zpio.h"

#define BUFFER_SIZE (64*1024)
#define MAX_PATH    260
#define REISHI_VID 0x25BE
#define REISHI_PID 0x001E
#define CONCURRENT 7
#define PIPE_IN 0x81

///////////////////////////////////////////////////////////////////////////////

typedef int (*directory_entry_callback)(void *that, const char *name, struct dirent *entry);

int directory(const char *path, directory_entry_callback callback, void *that) {
    DIR *pd = opendir(path);
    if (pd == NULL) {
        return errno;
    }
    int r = 0;
    for (struct dirent *e = readdir(pd); e != NULL; e = readdir(pd)) {
        char name[MAX_PATH];
        if (strcmp(e->d_name, ".") != 0 && strcmp(e->d_name, "..") != 0) {
            if (snprintf(name, sizeof(name), "%s/%s", path, e->d_name) >= (int)sizeof(name)) {
                warn("filename is too long!");
            }
            if ((r = callback(that, name, e)) != 0) {
                break;
            }
            if (e->d_type == DT_DIR) {
                if ((r = directory(name, callback, that)) != 0) {
                    break;
                }
            }
        }
        errno = 0;
    }
    if (r == 0) {
        r = errno;
    }
    closedir(pd);
    return r;
}

///////////////////////////////////////////////////////////////////////////////

struct usb_device_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t iManufacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
};

// usb_enumerate_callback return value is a set of:
enum {
    USB_DONT_CLOSE_FD  = 0x0001,
    USB_STOP = 0x0002
};

// Thus, return value of 0 is "close fd and keep going"
typedef int (*usb_enumerate_callback)(int fd, const char *name, struct usb_device_descriptor *desc, void *that);

typedef struct usb_enumerate_context_s {
    usb_enumerate_callback callback;
    void* that;
} usb_enumerate_context_t;

static int _usb_dir_callback(void *that, const char *name, struct dirent * entry) {
    usb_enumerate_context_t *ctx = (usb_enumerate_context_t *)that;
    struct usb_device_descriptor dd;
    int fd, r;

    if ((entry->d_type & DT_DIR) == 0) {
        fd = open(name, O_RDWR);
        if (fd < 0) {
            warn("Cannot open %s: %d", name, errno);
        }
        else {
            r = 0;
            if (read(fd, &dd, sizeof(dd)) < 0) {
                warn("Cannot read device descriptor from %s: %d", name, errno);
            }
            else {
                r = ctx->callback(fd, name, &dd, ctx->that);
            }
            if ((r & USB_DONT_CLOSE_FD) == 0) {
                close(fd);
            }
            if (r & USB_STOP) {
                return 0;
            }
        }
    }
    return 0;
}

// iterate over all connected devices
int usb_enumerate(usb_enumerate_callback uc, void *that) {
    usb_enumerate_context_t ctx;
    ctx.callback = uc;
    ctx.that = that;

    return directory("/dev/bus/usb", _usb_dir_callback, &ctx);
}

///////////////////////////////////////////////////////////////////////////////

struct reishi_device_s {
    int fd;
    char path[MAX_PATH]; // for logging

    reishi_sink sink;
    void* that;

    pthread_t thread;

    struct usbdevfs_urb urbs[CONCURRENT];
    char buffer[CONCURRENT*BUFFER_SIZE];
    zpio_t *z0;
    zpio_t *z1;
};
/*
static int bulk_out(int fd, __u8 pipe, void *data, int bytes) {
    struct usbdevfs_bulktransfer req;
    req.ep = pipe;
    req.len = bytes;
    req.timeout = 1000; // milliseconds
    req.data = data;
    return (ioctl(fd, USBDEVFS_BULK, &req) == bytes ? 0 : errno);
}

static int bulk_in(int fd, __u8 pipe, void *data, uint32_t bytes, uint32_t *received) {
    struct usbdevfs_bulktransfer req;
    req.ep = pipe;
    req.len = bytes;
    req.timeout = 1000; // milliseconds
    req.data = data;
    int r = ioctl(fd, USBDEVFS_BULK, &req);
    if (r >= 0) {
        *received = (uint32_t )r;
        return 0;
    }
    return errno;
}
*/
static int submit_urb(reishi_device_t *d, struct usbdevfs_urb *urb) {
    int r;

    do {
        r = ioctl(d->fd, USBDEVFS_SUBMITURB, urb);
    }
    while (r < 0 && errno == EINTR);
    return r;
}

static int read_urb(reishi_device_t *d, struct usbdevfs_urb** purb) {
    int r;

    do {
        r = ioctl(d->fd, USBDEVFS_REAPURB, purb);
    } while (r < 0 && errno == EINTR);
    return (r < 0) ?  errno : 0;
}

static void * io_thread(void *o) {
    reishi_device_t *d = (reishi_device_t*)o;
    struct usbdevfs_urb *urb;
    int r;

    for (int i = 0; i < CONCURRENT; ++i) {
        submit_urb(d, &d->urbs[i]);
    }
    info("io_thread warm");
    do {
        urb = NULL;
        if (d->z0 != NULL) { zpio_set(d->z0, 1); }
        r = read_urb(d, &urb);
        if (d->z0 != NULL) { zpio_set(d->z0, 0); }
	if (r != 0) info("read_urb(): %d", r);
        if (r == 0 && urb != NULL) {
            if (d->z1 != NULL) { zpio_set(d->z1, 1); }
            d->sink(d->that, urb->actual_length, urb->buffer);
            if (d->z1 != NULL) { zpio_set(d->z1, 0); }
            submit_urb(d, urb);
        }
    } while (r == 0 && d->thread != (pthread_t)0);
    info("io_thread exiting");
    return NULL;
}

///////////////////////////////////////////////////////////////////////////////

static reishi_device_t device;

static int available_callback(int fd, const char *name, struct usb_device_descriptor *desc, void *that) {
    reishi_device_t *d = (reishi_device_t*)that;
//    info("USB VID=%04X PID=%04X", desc->idVendor,desc->idProduct);
    if (desc->idVendor == REISHI_VID && desc->idProduct == REISHI_PID) {
        d->fd = fd;
        strncpy(d->path, name, sizeof(d->path));
        return USB_DONT_CLOSE_FD | USB_STOP;
    }
    return 0;
}

reishi_device_t* reishi_open(void *that, reishi_sink sink, zpio_t *z0, zpio_t *z1) {
    int i;
    reishi_device_t *d = &device;

    d->fd = -1;
    d->that = that;
    d->sink = sink;
    d->z0 = z0;
    d->z1 = z1;

    usb_enumerate(available_callback, d);
    if (d->fd < 0) {
        info("Could not find a reishi device");
        return NULL;
    }
    for (i = 0; i < CONCURRENT; ++i) {
        d->urbs[i].type = USBDEVFS_URB_TYPE_BULK;
        d->urbs[i].endpoint = PIPE_IN;
        d->urbs[i].flags = 0;
        d->urbs[i].buffer = d->buffer + i*BUFFER_SIZE;
        d->urbs[i].buffer_length = BUFFER_SIZE;
        d->urbs[i].start_frame = 0;
        d->urbs[i].stream_id = 0;
        d->urbs[i].error_count = 0;
        d->urbs[i].signr = 0;
        d->urbs[i].usercontext = d;
    }
    if_report(pthread_create(&d->thread, NULL, io_thread, d));
    return d;
}

void reishi_close(reishi_device_t *d) {
    pthread_t t = d->thread;
    d->thread = (pthread_t)0;
    if (d->fd >= 0){
        for (int i = 0; i < CONCURRENT; ++i) {
            ioctl(d->fd, USBDEVFS_DISCARDURB, &d->urbs[i]);
        }
        close(d->fd);
        d->fd = -1;
    }
    if (t != (pthread_t)0) {
        pthread_join(t, NULL);
    }
}

int reishi_control_transfer(reishi_device_t *d, __u8 rt, __u8 req, __u16 value, __u16 index,
        __u16 length, void *data) {
    struct usbdevfs_ctrltransfer ct;
    ct.bRequestType = rt & 0xFE;    // clear off interface bit
    ct.bRequest = req;
    ct.wValue = value;
    ct.wIndex = index;
    ct.wLength = length;
    ct.timeout = 10000;  //
    ct.data = data;
    int r = ioctl(d->fd, USBDEVFS_CONTROL, &ct);
//    info("reishi_control_transfer(): %d length=%d, ct.wLength=%d", r, length, ct.wLength);
    return r;
}

