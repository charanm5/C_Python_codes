#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5, pos = 3;

    int temp[pos];
    
    for (int i=0;i<pos;i++)
    {
        temp[i] = arr[i];
    }

    for (int i=pos;i<size;i++)
    {
        arr[i-pos] = arr[i];
    }

    for (int i=0; i<pos; i++)
    {
        arr[size-pos+i] = temp[i];
    }

    for (int i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}