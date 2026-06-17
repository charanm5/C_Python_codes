#include <stdio.h>

int main()
{
    int a = 10, b = 20, c = 30;

    printf("Address of a = %p\n", (void *)&a);
    printf("Address of b = %p\n", (void *)&b);
    printf("Address of c = %p\n", (void *)&c);

    return 0;
}