#ifndef REISHI_H
#define REISHI_H
#include "zpio.h"

typedef struct reishi_device_s reishi_device_t;
typedef void (*reishi_sink)(void *that, int bytes, void *data);

reishi_device_t *reishi_open(void *that, reishi_sink sink, zpio_t* z0, zpio_t* z1);
void reishi_close(reishi_device_t* device);

// returns number of bytes received or -1 on error
int reishi_control_transfer(reishi_device_t *d, __u8 rt, __u8 req,
        __u16 value, __u16 index, __u16 length, void *data);


#endif // REISHI_H

