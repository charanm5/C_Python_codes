#include <stdio.h>

int main()
{
    unsigned int num;
    int count;

    printf("Enter number: ");
    scanf("%u", &num);

    if (num == 0)
    {
        printf("Number of trailing zeros: 32\n");
        return 0;
    }

    count = 0;

    while ((num & 1U) == 0)
    {
        count++;
        num = num >> 1;
    }

    printf("Number of trailing zeros: %d\n", count);

    return 0;
}