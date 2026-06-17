#include <stdio.h>

int main()
{
    unsigned int num, result;
    int n;

    printf("Enter an integer: ");
    scanf("%u", &num);

    printf("Enter n: ");
    scanf("%d", &n);

    result = num | 0xFF;
    printf("Set all bits in LSB byte      : %u\n", result);

    result = num | 0xFF000000;
    printf("Set all bits in MSB byte      : %u\n", result);

    result = num | 0x0F;
    printf("Set all bits in LSB nibble    : %u\n", result);

    result = num | 0xF0000000;
    printf("Set all bits in MSB nibble    : %u\n", result);

    result = num | ((1U << n) - 1);
    printf("Set %d bits                   : %u\n", n, result);

    result = num & ~((1U << n) - 1);
    printf("Clear %d bits                 : %u\n", n, result);

    result = num ^ ((1U << n) - 1);
    printf("Toggle %d bits                : %u\n", n, result);

    return 0;
}