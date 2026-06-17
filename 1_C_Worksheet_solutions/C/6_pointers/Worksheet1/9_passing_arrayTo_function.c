#include <stdio.h>

void display(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d\n", *(arr + i));
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50}, n = 5;

    display(arr, n);

    return 0;
}