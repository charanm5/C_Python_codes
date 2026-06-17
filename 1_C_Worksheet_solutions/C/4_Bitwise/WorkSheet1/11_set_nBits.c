#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int mask;
    unsigned int ybits;

    mask = ((1U << n) - 1) << (p - n + 1);
    ybits = (y & ((1U << n) - 1)) << (p - n + 1);

    return (x & ~mask) | ybits;
}

int main()
{
    unsigned int x,y,result;
    int p,n;

    printf("Enter x: ");
    scanf("%u", &x);

    printf("Enter y: ");
    scanf("%u", &y);

    printf("Enter position p: ");
    scanf("%d", &p);

    printf("Enter number of bits n: ");
    scanf("%d", &n);

    result = setbits(x, p, n, y);

    printf("Result = %u\n", result);

    return 0;
}