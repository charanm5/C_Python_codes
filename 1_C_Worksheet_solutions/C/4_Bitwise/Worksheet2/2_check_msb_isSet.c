#include <stdio.h>

int main()
{
    unsigned int num, msb, mask;

    printf("Enter a number: ");
    scanf("%u", &num);

    mask = 1U << 31;
    msb = num & mask;

    if (msb)
        printf("MSB of %u is set (1)\n", num);
    else
        printf("MSB of %u is not set (0)\n", num);

    return 0;
}