#include <stdio.h>

int main()
{
    float f;
    unsigned int bits;
    int count;

    printf("Enter a float: ");
    scanf("%f", &f);

    bits = *(unsigned int *)&f;

    count = 0;
    while (bits)
    {
        count += bits & 1;
        bits >>= 1;
    }

    printf("Number of set bits = %d\n", count);

    return 0;
}