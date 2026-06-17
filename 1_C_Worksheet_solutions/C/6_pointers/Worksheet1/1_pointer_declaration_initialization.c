#include <stdio.h>

int main()
{
    int a = 5, *ptr;

    ptr = &a;

    printf("a = %d\n", a);
    printf("*ptr = %d\n", *ptr);

    return 0;
}