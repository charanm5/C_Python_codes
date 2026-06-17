#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5, pos = 1;

    int temp[pos];

    // Store last pos elements
    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[size - pos + i];
    }

    // Shift remaining elements right
    for (int i = size - pos - 1; i >= 0; i--)
    {
        arr[i + pos] = arr[i];
    }

    // Copy stored elements to beginning
    for (int i = 0; i < pos; i++)
    {
        arr[i] = temp[i];
    }

    // Print array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}