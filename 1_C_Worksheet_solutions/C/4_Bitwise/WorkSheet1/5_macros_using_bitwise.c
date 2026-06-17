#include <stdio.h>

#define SET_BIT(num, n)    ((num) | (1U << (n)))
#define CLEAR_BIT(num, n)  ((num) & ~(1U << (n)))
#define TOGGLE_BIT(num, n) ((num) ^ (1U << (n)))

int main()
{
    unsigned int num;
    int n;

    printf("Enter an integer: ");
    scanf("%u", &num);

    printf("Enter bit position: ");
    scanf("%d", &n);

    printf("Set Bit    : %u\n", SET_BIT(num, n));
    printf("Clear Bit  : %u\n", CLEAR_BIT(num, n));
    printf("Toggle Bit : %u\n", TOGGLE_BIT(num, n));

    return 0;
}