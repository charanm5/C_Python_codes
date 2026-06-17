#include <stdio.h>

int countBitsMethod1(unsigned int n)
{
    unsigned int count, i;
    count = 0;

    for (i = 0; i < 32; i++)
    {
        if (n & (1U << i))
            count++;
    }

    return count;
}

int countBitsMethod2(unsigned int n)
{
    unsigned int count;

    count = 0;

    while (n)
    {
        count += (n & 1U);
        n >>= 1;
    }

    return count;
}

int main()
{
    unsigned int num;
    unsigned int bit20;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Method 1 Count = %d\n", countBitsMethod1(num));
    printf("Method 2 Count = %d\n", countBitsMethod2(num));

    bit20 = (num & (1U << 19));

    if (bit20)
        printf("20th bit is SET\n");
    else
        printf("20th bit is NOT SET\n");

    return 0;
}