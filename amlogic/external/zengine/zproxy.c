#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#include "zgadget.h"
#include "trace.h"
#include "reishi.h"
#include "zpio.h"

typedef struct zen_app_s {
    volatile int saw_SIGINT;
    zgadget_t *zg;
    reishi_device_t *reishi;
    zpio_t zpio[4];
} zen_app_t;

zen_app_t app;

static void on_signal(int sig, siginfo_t *info, void *ptr)
{
    (void)info;
    if (sig == SIGINT || sig == SIGQUIT)
       app.saw_SIGINT ++;
    note("on_signal(%d) -> %d", sig, app.saw_SIGINT);
}

static void install_signal_hooks()
{
    struct sigaction action;
    action.sa_sigaction = on_signal;
    sigfillset (&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    die_on(sigaction (SIGINT, &action, NULL) < 0, "sigaction(SIGINT)");
    die_on(sigaction (SIGQUIT, &action, NULL) < 0,"sigaction(SIGQUIT)");
}

static int
ep0_callback(void *that, byte rt, byte req, uint16_t value, uint16_t index, uint16_t length, byte *buf) {
    zen_app_t *app = (zen_app_t*)that;
    if (app->reishi != NULL)
        return reishi_control_transfer(app->reishi, rt, req, value, index, length, buf);
    return 0;
}

static int out_callback(void *that, const void *buf, int bytes) {
    info("Unexpected OUT packet: %d bytes\n", bytes);
    return bytes;
}

static void sink(void *that, int bytes, void *data) {
    zen_app_t *app = (zen_app_t *)that;
    if (app != NULL && app->zg != NULL)
        zg_write(app->zg, data, bytes);
}

int main(/* int ac, char *av[] */) {
    info("zproxy starting up\n");
    install_signal_hooks();
    zpio_open(&app.zpio[0], 236);
    zpio_open(&app.zpio[1], 237);
    zpio_open(&app.zpio[2], 238);
    zpio_open(&app.zpio[3], 239);
    info("zproxy zpio: %d %d %d %d\n", app.zpio[0].fd, app.zpio[1].fd, app.zpio[2].fd, app.zpio[3].fd);
    app.reishi = reishi_open(&app, sink, &app.zpio[0], &app.zpio[1]);
    zg_open(&app.zg, ep0_callback, out_callback, &app, &app.zpio[2], &app.zpio[3]);

    while (app.saw_SIGINT == 0) {
        if (app.reishi == NULL) {
            app.reishi = reishi_open(&app, sink, &app.zpio[0], &app.zpio[1]);
        }
        sleep(1);
    }
    if (app.reishi != NULL)
        reishi_close(app.reishi);
    zpio_close(&app.zpio[0]);
    zpio_close(&app.zpio[1]);
    zpio_close(&app.zpio[2]);
    zpio_close(&app.zpio[3]);
    zg_close(app.zg);
    info("zproxy stopped\n");
    return 0;
}
