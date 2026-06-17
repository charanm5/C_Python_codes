#include <stdio.h>
#include <stdlib.h>

void allocateInt(int **pp)
{
    *pp = (int *)malloc(sizeof(int));
}

void allocateArray(int **pp, int n)
{
    *pp = (int *)malloc(n * sizeof(int));
}

int main()
{
    int *p = NULL;
    int **pp = &p;
    int i, n = 5;

    allocateInt(pp);
    if (*pp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    **pp = 10;
    printf("Single value: %d\n", **pp);

    free(*pp);

    allocateArray(pp, n);
    if (*pp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        *(*pp + i) = (i + 1) * 10;
    }

    printf("Array values:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", *(*pp + i));
    }

    free(*pp);

    return 0;
}