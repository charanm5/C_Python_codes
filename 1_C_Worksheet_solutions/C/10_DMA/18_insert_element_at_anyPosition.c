#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i, pos, value;

    scanf("%d", &n);

    arr = malloc(n * sizeof(int));
    if (arr == NULL)
        return 1;

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position to insert value: ")
    scanf("%d", &pos);

    if (pos < 0 || pos > n)
    {
        free(arr);
        return 1;
    }

    printf("Enter th value: ");
    scanf("%d", &value);

    int *temp = realloc(arr, (n + 1) * sizeof(int));
    if (temp == NULL)
    {
        free(arr);
        return 1;
    }

    arr = temp;

    for (i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;

    printf("Final array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}