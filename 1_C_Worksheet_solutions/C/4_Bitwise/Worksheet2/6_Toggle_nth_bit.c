#include <stdio.h>

int main()
{
    unsigned int num, n, result;

    printf("Enter number: ");
    scanf("%u", &num);

    printf("Enter bit position: ");
    scanf("%u", &n);

    result = num ^ (1U << n);

    printf("Number after toggling bit %u: %u\n", n, result);

    return 0;
}