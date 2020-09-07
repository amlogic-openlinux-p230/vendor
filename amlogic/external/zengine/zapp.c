#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include "reishi.h"
#include "trace.h"

typedef unsigned char byte;
#define CAT_FPGA        0x00
#define CAT_SENSOR      0x01
#define CAT_I2C         0x02
#define CAT_STY         0x03

#define SET_BIG         0x04
#define SET_ACC         0x04
#define SET_STY         0x04
#define SET_ALL         0x0F
#define REG_THRESHOLD   0x02

static void sink(void *that, int bytes, void *data) {
    (void)that; (void)bytes; (void)data;
}

static int dispatcher_set(reishi_device_t *d, byte cat, byte set, int value) {
    byte buf[4];
    uint16_t wValue = ((cat & 0x0F) << 12) | ((set & 0x0F) << 8) | ((value >> 16) & 0xFF);
    uint16_t wIndex = (value & 0xFFFF);
    return reishi_control_transfer(d, 0x41, 0x10, wValue, wIndex, 0, buf);
}

static int dispatcher_get(reishi_device_t *d, byte cat, byte set, int value, void *result) {
    uint16_t wValue = ((cat & 0x0F) << 12) | ((set & 0x0F) << 8) | ((value >> 16) & 0xFF);
    uint16_t wIndex = (value & 0xFFFF);
    return reishi_control_transfer(d, 0xC1, 0x10, wValue, wIndex, 4, result);
}

int reishi_set_fpga(reishi_device_t *d, byte set, byte reg, uint16_t value) {
    return dispatcher_set(d, CAT_FPGA, set, (reg << 16) | value);
}

int reishi_get_fpga(reishi_device_t * d, byte set, byte reg, uint16_t *value) {
    byte result[4] = { 0, };
    int r = dispatcher_get(d, CAT_FPGA, set, (reg << 16), result);
    if (r < 0)
        return r;
    if (r != 4)
        return -EPIPE;
    if (result[2] != 0)
        return -result[2];
    *value = result[0] | (result[1] << 8);
    return 0;
}
int reishi_set_sensor(reishi_device_t *d, byte set, short reg, byte data) {
    return dispatcher_set(d, CAT_SENSOR, set, (reg << 8) | data);
}
    
int reishi_get_sensor(reishi_device_t *d, byte set, short reg, byte *data) {
    byte result[4] = { 0, };
    int r = dispatcher_get(d, CAT_SENSOR, set, (reg << 8), result);
    if (r < 0)
        return r;
    if (r != 4)
        return -EPIPE;
    if (result[1] != 0)
        return -result[1];
    *data = result[0];
    return 0;
}

int reishi_set_stylus(reishi_device_t *d, byte i2c, byte reg, byte data) {
    return dispatcher_set(d, CAT_STY, SET_STY, (i2c << 16) | (reg << 8) | data);    
}

int reishi_get_stylus(reishi_device_t *d, byte i2c, byte reg, byte *data) {
    byte result[4] = { 0, };
    int r = dispatcher_get(d, CAT_STY, SET_STY, (i2c << 16) | (reg << 8), result);
    if (r < 0)
        return r;
    if (r != 4)
        return -EPIPE;
    if (result[1] != 0)
        return -result[1];
    *data = result[0];
    return 0;
}

static int get_sensor_chipid(reishi_device_t *d, byte set, uint32_t *cid) {
    byte a=0,b=0,c=0,e=0;
    if_return(reishi_get_sensor(d, set, 0x300A, &a));
    if_return(reishi_get_sensor(d, set, 0x300B, &b));
    if_return(reishi_get_sensor(d, set, 0x300C, &c));
    if (a == 0x77 && b == 0x50) {
        if_return(reishi_get_sensor(d, set, 0x3029, &e));
    }
    *cid = (a<<24) | (b<<16) | (c<<8) | e;
    return 0;
}

int main(int ac, char *av[]) {
    reishi_device_t *d = reishi_open(NULL, sink, NULL, NULL);
    if (d == NULL) {
        fprintf(stderr, "Cannot open reishi device\n");
        return -1;
    }
    uint16_t v = 0;
    if_return(reishi_get_fpga(d, SET_BIG, 0x10, &v));
    fprintf(stderr, "FPGA version: %04X\n", (int)v);

    for (int i = 0; i < 3; ++i) {
        uint32_t cid = 0;
        if_return(get_sensor_chipid(d, (1<<i), &cid));
        fprintf(stderr, "Sensor %d chipid: 0x%08X\n", i, cid);
    }

    byte b = 0;
    if_return(reishi_get_stylus(d, 0x69, 0x75, &b));
    fprintf(stderr, "Stylus chipid: %02X\n", b);

    reishi_set_fpga(d, SET_ALL, 0x03, 0x0000);  // turn off LEDs

    reishi_close(d);
    return 0;
}
