#include <stdio.h>

int main()
{
    unsigned int num, oddBits, evenBits, result;

    printf("Enter a number: ");
    scanf("%u", &num);

    oddBits = num & 0xAAAAAAAA;
    evenBits = num & 0x55555555;

    oddBits >>= 1;
    evenBits <<= 1;

    result = oddBits | evenBits;

    printf("Result = %u\n", result);

    return 0;
}