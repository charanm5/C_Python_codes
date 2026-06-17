#include <stdio.h>

int main()
{
    unsigned int num;
    int count, i;

    printf("Enter number: ");
    scanf("%u", &num);

    count = 0;

    for (i = 31; i >= 0; i--)
    {
        if ((num & (1U << i)) == 0)
            count++;
        else
            break;
    }

    printf("Number of leading zeros: %d\n", count);

    return 0;
}