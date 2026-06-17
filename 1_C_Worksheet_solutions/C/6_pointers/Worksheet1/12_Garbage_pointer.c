#include <stdio.h>

int main()
{
    int a = 10, *p;

    printf("Uninitialized pointer (unsafe):\n");
    printf("*p = %d\n", *p);

    p = &a;

    printf("After initialization:\n");
    printf("*p = %d\n", *p);

    return 0;
}