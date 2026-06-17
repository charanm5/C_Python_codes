#include <stdio.h>

int main()
{
    unsigned int num, result, mask;

    printf("Enter number: ");
    scanf("%u", &num);

    mask = 0xFF;
    result = (~num) & mask;

    printf("Flipped bits: %u\n", result);

    return 0;
}