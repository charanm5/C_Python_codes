#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int id;
    float value;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void modifyArray(int *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        *(p + i) = *(p + i) * 2;
    }
}

void updateStruct(struct Data *s)
{
    s->id = 100;
    s->value = 99.5f;
}

int main()
{
    int x = 10, y = 20;
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    struct Data d = {1, 10.5f};

    struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
    *pd = d;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n\n", x, y);

    printf("Before array modification:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    modifyArray(arr, n);

    printf("\nAfter array modification:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nBefore struct update: id = %d, value = %.2f\n", d.id, d.value);

    updateStruct(pd);

    printf("After struct update: id = %d, value = %.2f\n", pd->id, pd->value);

    free(pd);

    return 0;
}