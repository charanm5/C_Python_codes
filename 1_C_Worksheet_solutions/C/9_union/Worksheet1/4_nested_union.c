#include <stdio.h>

union Number
{
    int i;
    union
    {
        float f;
        char c;
    } inner;
};

int main()
{
    union Number num;

    num.i = 100;
    printf("Outer union int: %d\n", num.i);

    num.inner.f = 12.5f;
    printf("Inner union float: %.2f\n", num.inner.f);

    num.inner.c = 'A';
    printf("Inner union char: %c\n", num.inner.c);

    return 0;
}