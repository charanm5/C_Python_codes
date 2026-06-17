#include <stdio.h>

int main()
{
    unsigned int x;
    int bits;

    x = ~0U;
    bits = 0;

    while (x)
    {
        bits++;
        x >>= 1;
    }

    printf("Size of unsigned int = %d bits\n", bits);

    return 0;
}