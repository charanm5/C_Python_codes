#include <stdio.h>
#include <stdint.h>

struct Peripheral {
    uint8_t status;
    uint8_t control;
    uint16_t data;
};

int main() {
    struct Peripheral peripherals[5];
    struct Peripheral *ptr = peripherals;

    for (int i = 0; i < 5; i++) {
        (ptr + i)->status = i;
        (ptr + i)->control = i + 10;
        (ptr + i)->data = (i + 1) * 100;
    }

    for (int i = 0; i < 5; i++) {
        printf("Peripheral %d: status=%u control=%u data=%u\n",
               i,
               (ptr + i)->status,
               (ptr + i)->control,
               (ptr + i)->data);
    }

    return 0;
}