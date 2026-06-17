#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50}, *p = arr, i;

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", *(p + i));
    }

    return 0;
}