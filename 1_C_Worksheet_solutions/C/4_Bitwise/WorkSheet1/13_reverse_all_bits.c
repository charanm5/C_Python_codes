#include <stdio.h>

int main()
{
    unsigned int num,reversed;
    int i;

    printf("Enter a number: ");
    scanf("%u", &num);

    reversed = 0;

    for (i = 0; i < 32; i++)
    {
        reversed <<= 1;
        reversed |= (num & 1);
        num >>= 1;
    }

    printf("Reversed bits value = %u\n", reversed);

    return 0;
}