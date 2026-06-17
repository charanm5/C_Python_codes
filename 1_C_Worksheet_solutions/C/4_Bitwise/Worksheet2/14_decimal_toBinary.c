#include <stdio.h>

int main()
{
    unsigned int num;
    int i, started;

    printf("Enter number: ");
    scanf("%u", &num);

    started = 0;

    printf("Binary representation: ");

    for (i = 31; i >= 0; i--)
    {
        if (num & (1U << i))
        {
            printf("1");
            started = 1;
        }
        else
        {
            if (started)
                printf("0");
        }
    }

    if (!started)
        printf("0");

    printf("\n");

    return 0;
}