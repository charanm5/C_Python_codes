#include <stdio.h>

int main()
{
    unsigned int num, n, bit;

    printf("Enter number: ");
    scanf("%u", &num);

    printf("Enter bit position: ");
    scanf("%u", &n);

    bit = (num >> n) & 1U;

    printf("Bit %u of %u is %u\n", n, num, bit);

    return 0;
}