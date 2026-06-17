#include <stdio.h>
#include <stdarg.h>

void sort_numbers(int count, ...)
{
    int arr[count];
    va_list args;

    va_start(args, count);

    /* Store variadic arguments in an array */
    for (int i = 0; i < count; i++)
    {
        arr[i] = va_arg(args, int);
    }

    va_end(args);

    /* Sort the array using Bubble Sort */
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    /* Print sorted numbers */
    printf("Sorted numbers: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    sort_numbers(5, 9, 5, 7, 1, 3);
    sort_numbers(3, 1, -2, 0);

    return 0;
}