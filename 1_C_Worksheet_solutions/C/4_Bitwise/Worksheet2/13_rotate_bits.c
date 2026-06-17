#include <stdio.h>

int main()
{
    unsigned int num, result, n, choice, bits;

    printf("Enter number: ");
    scanf("%u", &num);

    printf("Enter number of positions to rotate: ");
    scanf("%u", &n);

    printf("Enter choice (1=left, 2=right): ");
    scanf("%u", &choice);

    bits = 32;

    if (choice == 1)
    {
        result = (num << n) | (num >> (bits - n));
    }
    else
    {
        result = (num >> n) | (num << (bits - n));
    }

    printf("Result after rotation: %u\n", result);

    return 0;
}