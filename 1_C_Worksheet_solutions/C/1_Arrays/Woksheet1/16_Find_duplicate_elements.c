#include <stdio.h>

int main()
{
    int size = 6;
    int arr[] = {1,2,3,2,4,1},flag;

    printf("Duplicate elements:\n");

    for (int i=0;i<size;i++)
    {
        flag = 0;

        for (int k=0;k<i;k++)
        {
            if (arr[i] == arr[k])
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            continue;

        int count = 0;
        for (int j=i+1;j<size;j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > 0)
            printf("%d ", arr[i]);
    }
}