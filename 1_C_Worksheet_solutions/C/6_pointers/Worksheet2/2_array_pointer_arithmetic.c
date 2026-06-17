#include <stdio.h>

void reverse(int *p, int n)
{
    int *start = p;
    int *end = p + n - 1;
    int temp;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    int n = 5;
    int sum = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        sum += *p;
        p++;
    }

    printf("Sum = %d\n", sum);

    reverse(arr, n);

    printf("Reversed array:\n");

    p = arr;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", *p);
        p++;
    }

    return 0;
}