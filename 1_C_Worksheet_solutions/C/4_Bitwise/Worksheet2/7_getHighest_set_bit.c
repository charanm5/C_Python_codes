#include <stdio.h>

int main()
{
    unsigned int num;
    int pos;

    printf("Enter number: ");
    scanf("%u", &num);

    pos = -1;

    while (num)
    {
        pos++;
        num = num >> 1;
    }

    if (pos == -1)
        printf("No set bits (number is 0)\n");
    else
        printf("Highest set bit is at position %d\n", pos);

    return 0;
}