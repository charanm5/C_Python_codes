#include <stdio.h>

int main()
{
    unsigned int num, msbMask;
    int n;

    printf("Enter an integer: ");
    scanf("%u", &num);

    printf("Enter bit position: ");
    scanf("%d", &n);

    if (num & 1)
        printf("LSB is set\n");
    else
        printf("LSB is not set\n");

    msbMask = 1U << (sizeof(unsigned int) * 8 - 1);

    if (num & msbMask)
        printf("MSB is set\n");
    else
        printf("MSB is not set\n");

    if (num & (1U << n))
        printf("Bit %d is set\n", n);
    else
        printf("Bit %d is not set\n", n);

    return 0;
}