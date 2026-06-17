#include <stdio.h>

int main()
{
    int a = 10, *p = NULL;

    if (p != NULL)
    {
        printf("%d\n", *p);
    }
    else
    {
        printf("Pointer is NULL\n");
    }

    p = &a;

    if (p != NULL)
    {
        printf("%d\n", *p);
    }

    return 0;
}