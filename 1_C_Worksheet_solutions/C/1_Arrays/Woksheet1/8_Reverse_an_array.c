#include<stdio.h>

int main()
{
    int size=5,i,temp,indx=size-1;
    int arr[] = {1,2,3,4,5};
    for(i=0;i<size/2;i++)
    {
        temp = arr[indx-i];
        arr[indx-i] = arr[i];
        arr[i] = temp;
    }
    printf("The reversed array is : ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}