#include <stdio.h>

int main()
{
    int arr[] = {2, 4, 6}, *p = arr, i;

    for (i = 0; i < 3; i++)
    {
        *(p + i) = *(p + i) + 1;
    }

    for (i = 0; i < 3; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}