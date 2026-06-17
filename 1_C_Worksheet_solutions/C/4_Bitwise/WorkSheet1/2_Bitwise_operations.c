#include <stdio.h>

int main() {
    int num, pos;
    int bits = sizeof(int) * 8;
    int msbMask = 1 << (bits - 1);

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("\nEnter bit position (0-based index): ");
    scanf("%d", &pos);

    printf("\nLSB Operations:\n");
    printf("Set LSB     : %d\n", num | 1);
    printf("Clear LSB   : %d\n", num & ~1);
    printf("Toggle LSB  : %d\n", num ^ 1);

    printf("\nMSB Operations:\n");
    printf("Set MSB     : %d\n", num | msbMask);
    printf("Clear MSB   : %d\n", num & ~msbMask);
    printf("Toggle MSB  : %d\n", num ^ msbMask);

    printf("\nSpecific Bit Operations at position %d:\n", pos);
    printf("Set Bit     : %d\n", num | (1 << pos));
    printf("Clear Bit   : %d\n", num & ~(1 << pos));
    printf("Toggle Bit  : %d\n", num ^ (1 << pos));

    return 0;
}