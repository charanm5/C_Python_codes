#include <stdio.h>

void init(void) {
    printf("Device initialized\n");
}

void start(void) {
    printf("Device started\n");
}

void stop(void) {
    printf("Device stopped\n");
}

typedef enum {
    CMD_INIT,
    CMD_START,
    CMD_STOP,
    CMD_COUNT
} Command;

void (*cmd_table[])(void) = {
    init,
    start,
    stop
};

int main(void) {
    Command cmd;

    cmd = CMD_INIT;
    cmd_table[cmd]();

    cmd = CMD_START;
    cmd_table[cmd]();

    cmd = CMD_STOP;
    cmd_table[cmd]();

    return 0;
}