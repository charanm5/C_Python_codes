#include <stdio.h>
#include <stdlib.h>

struct Register {
    unsigned int control;
    unsigned int status;
    unsigned int data;
};

int main() {
    struct Register *reg;

    reg = (struct Register *)malloc(sizeof(struct Register));

    if (reg == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    reg->control = 0x01;
    reg->status  = 0x00;
    reg->data    = 0xFF;

    printf("CONTROL = %u\n", reg->control);
    printf("STATUS  = %u\n", reg->status);
    printf("DATA    = %u\n", reg->data);

    printf("\nSimulating memory-mapped peripheral access:\n");

    reg->control |= 0x02;
    reg->status  |= 0x01;
    reg->data    = 1234;

    printf("CONTROL = %u\n", reg->control);
    printf("STATUS  = %u\n", reg->status);
    printf("DATA    = %u\n", reg->data);

    free(reg);
    reg = NULL;

    return 0;
}