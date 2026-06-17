#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5, i;
    int *arr = NULL;

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    printf("After malloc:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    arr = (int *)realloc(arr, 10 * sizeof(int));
    if (arr == NULL)
    {
        printf("realloc failed\n");
        return 1;
    }

    for (i = 5; i < 10; i++)
    {
        arr[i] = (i + 1) * 10;
    }

    printf("After realloc:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    int *brr = NULL;

    brr = (int *)calloc(5, sizeof(int));
    if (brr == NULL)
    {
        printf("calloc failed\n");
        return 1;
    }

    printf("Array from calloc (initialized to 0):\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", brr[i]);
    }

    printf("\n");

    free(brr);

    return 0;
}