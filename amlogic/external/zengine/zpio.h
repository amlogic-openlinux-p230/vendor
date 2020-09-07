#ifndef ZPIO_H
#define ZPIO_H

typedef struct zpio_s {
    int gpio;
    int fd;
} zpio_t;

int zpio_open(zpio_t* zpio, int gpio);
int zpio_close(zpio_t *zpio);
int zpio_set(zpio_t *zpio, int value);

#endif // ZPIO_H

