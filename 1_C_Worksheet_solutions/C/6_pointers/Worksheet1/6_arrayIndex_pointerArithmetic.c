#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50}, i;

    for (i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d, *(arr + %d) = %d\n",
               i, arr[i], i, *(arr + i));
    }

    return 0;
}