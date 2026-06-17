#include <stdio.h>

int main()
{
    unsigned int num;
    int pos;

    printf("Enter number: ");
    scanf("%u", &num);

    pos = 0;

    if (num == 0)
    {
        printf("No set bits (number is 0)\n");
        return 0;
    }

    while ((num & 1U) == 0)
    {
        num = num >> 1;
        pos++;
    }

    printf("Lowest set bit is at position %d\n", pos);

    return 0;
}