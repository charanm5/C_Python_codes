#include <stdio.h>

int main()
{
    int a = 10, *p = &a;

    *p = 20;

    printf("a = %d\n", a);
    printf("*p = %d\n", *p);

    return 0;
}