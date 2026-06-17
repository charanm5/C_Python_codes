#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size=20,i,val,indx;
    int arr[]={1,2,3,4,5};
    printf("Enter index to delete an element: ");
    scanf("%d",&indx);
    for(i=indx;i<size-1;i++)
    {
        arr[i] = arr[i+1];
    }
    
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}