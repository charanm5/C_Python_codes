#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size=5,i,temp,j;
    int arr[]={4,2,1,3,5};
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}