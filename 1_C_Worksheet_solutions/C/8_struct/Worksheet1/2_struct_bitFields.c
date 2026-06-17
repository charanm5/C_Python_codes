#include <stdio.h>

struct StatusRegister {
    unsigned int error : 1;
    unsigned int ready : 1;
    unsigned int mode  : 2;
    unsigned int reserved : 4;
};

void printRegister(struct StatusRegister r) {
    printf("ERROR  = %u\n", r.error);
    printf("READY  = %u\n", r.ready);
    printf("MODE   = %u\n", r.mode);
}

int main() {
    struct StatusRegister reg = {0};

    reg.error = 1;
    reg.ready = 0;
    reg.mode = 2;

    printf("Initial Register State:\n");
    printRegister(reg);

    reg.error = 0;
    printf("\nAfter clearing ERROR flag:\n");
    printRegister(reg);

    reg.ready = 1;
    printf("\nAfter setting READY flag:\n");
    printRegister(reg);

    reg.mode = 3;
    printf("\nAfter changing MODE:\n");
    printRegister(reg);

    printf("\nSize of bit-field struct = %lu bytes\n", sizeof(reg));

    return 0;
}