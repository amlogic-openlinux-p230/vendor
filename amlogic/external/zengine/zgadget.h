#ifndef ZGADGET_H
#define ZGADGET_H
#include <stdint.h>
#include "zpio.h"

typedef uint8_t byte;
typedef struct zgadget_s zgadget_t;

typedef int (*zg_ep0_callback)(void *that, byte rt, byte req, uint16_t value, uint16_t index, uint16_t length, byte *buf);
typedef int (*zg_out_callback)(void *that, const void *buf, int bytes);

int zg_open(zgadget_t ** pz, zg_ep0_callback ep0, zg_out_callback out, void *that, zpio_t* z0, zpio_t *z1);
ssize_t zg_write(zgadget_t *t, const void *buf, int bytes);
int zg_close(zgadget_t *z);

#endif // ZGADGET_H
