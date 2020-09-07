#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "zpio.h"
#include "trace.h"

int zpio_open(zpio_t* zpio, int gpio) {
    char buf[256];
    zpio->gpio = gpio;
    zpio->fd = -1;
/* gpio configuration must be done externally/manually */
/*    int fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd <= 0) {
        info("open(/sys/class/gpio/export): %d\n", errno);
        return errno;
    }
    sprintf(buf, "%d", gpio);
    if (write(fd, buf, strlen(buf)) != (ssize_t)strlen(buf)) {
        int e = errno;
        info("write(/sys/class/gpio/export): %d\n", e);
        close(fd);
        return e;
    }
    close(fd);
    sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
    fd = open(buf, O_WRONLY);
    if (fd <= 0) {
        info("open(%s): %d\n", buf, errno);
        return errno;
    }
    if (write(fd, "out", 3) != 3) {
        int e = errno;
        info("writ(%s): %d\n", buf, errno);
        close(fd);
        return e;
    }
    close(fd);*/
    sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
    zpio->fd = open(buf, O_WRONLY);
    if (zpio->fd <= 0) {
        info("open(%s): %d\n", buf, errno);
        return errno;
    }
    return 0;
}

int zpio_close(zpio_t *zpio) {
    char buf[256];
    if (zpio->fd <= 0)
        return 0;
    close(zpio->fd);
    zpio->fd = -1;
    sprintf(buf, "%d", zpio->gpio);
    int fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd <= 0)
        return errno;
    if (write(fd, buf, strlen(buf)) != (ssize_t)strlen(buf)) {
        int e = errno;
        close(fd);
        return e;
    }
    return 0;
}

int zpio_set(zpio_t *zpio, int value) {
    if (zpio->fd <= 0)
        return EBADF;
    lseek(zpio->fd, 0, SEEK_SET);
    ssize_t cb = write(zpio->fd, value ? "1" : "0", 1);
    return cb == 1 ? 0 : errno;
}

