#include <stdio.h>

int main()
{
    int a = 5, *p = &a, **pp = &p;

    printf("a = %d\n", a);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);

    return 0;
}