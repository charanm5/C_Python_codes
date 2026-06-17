#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    int i;

    printf("Array name (arr) address = %p\n", (void *)arr);
    printf("Pointer (ptr) address = %p\n", (void *)ptr);
    printf("Address of array = %p\n\n", (void *)&arr);

    printf("Size of arr = %lu bytes\n", sizeof(arr));
    printf("Size of ptr = %lu bytes\n\n", sizeof(ptr));

    printf("Access using array name:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nAccess using pointer arithmetic:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n");

    return 0;
}