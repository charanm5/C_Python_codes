#include <stdio.h>

int main()
{
    unsigned int A,B,x;
    int count;

    printf("Enter A and B: ");
    scanf("%u %u", &A, &B);

    x = A ^ B;
    count = 0;

    while (x)
    {
        x = x & (x - 1);
        count++;
    }

    printf("Number of bits to be flipped = %d\n", count);

    return 0;
}