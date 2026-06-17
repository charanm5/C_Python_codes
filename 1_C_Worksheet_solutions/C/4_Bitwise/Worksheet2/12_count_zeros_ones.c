#include <stdio.h>

int main()
{
    unsigned int num, i, ones, zeros, bit;

    printf("Enter number: ");
    scanf("%u", &num);

    ones = 0;
    zeros = 0;

    for (i = 0; i < 8; i++)
    {
        bit = (num >> i) & 1U;

        if (bit == 1)
            ones++;
        else
            zeros++;
    }

    printf("Number of ones: %u, Number of zeros: %u\n", ones, zeros);

    return 0;
}