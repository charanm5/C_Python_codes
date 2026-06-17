#include <stdio.h>

int main()
{
    unsigned int num;
    int count;

    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    count = 0;

    while (num)
    {
        count += num & 1;
        num >>= 1;
    }

    printf("Number of set bits = %d\n", count);

    return 0;
}