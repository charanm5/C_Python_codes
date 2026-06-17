#include <stdio.h>

int main()
{
    int size = 6;
    int arr[] = {2,3,2,4,3,5};

    for (int i=0;i<size;i++)
    {
        for (int j=i+1;j<size;j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k=j;k<size-1;k++)
                {
                    arr[k] = arr[k+1];
                }
                size--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates: ");

    for (int i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}