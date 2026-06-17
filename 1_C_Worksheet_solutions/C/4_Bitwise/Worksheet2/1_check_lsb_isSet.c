#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num & 1)
        printf("LSB of %d is set (1)\n", num);
    else
        printf("LSB of %d is not set (0)\n", num);

    return 0;
}