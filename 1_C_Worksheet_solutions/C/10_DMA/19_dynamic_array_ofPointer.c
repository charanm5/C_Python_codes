#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int **arr;

    printf("Enter count: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int *));
    if (arr == NULL)
        return 1;

    for (i = 0; i < n; i++)
    {
        arr[i] = malloc(sizeof(int));
        if (arr[i] == NULL)
            return 1;

        printf("Enter value for element %d: ", i);
        scanf("%d", arr[i]);
    }

    printf("Values are: ");

    for (i = 0; i < n; i++)
        printf("%d ", *arr[i]);

    for (i = 0; i < n; i++)
        free(arr[i]);

    free(arr);

    return 0;
}