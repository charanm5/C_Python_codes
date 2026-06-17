#include<stdio.h>

int main()
{
    int size=5,i;
    int arr[] = {1,2,3,4,5};
    int copy_arr[size];
    for(i=0;i<size;i++)
    {
        copy_arr[i] = arr[i];
    }
    printf("Copied array elements are: ");
    for(i=0;i<size;i++)
    {
        printf("%d ",copy_arr[i]);
    }
}