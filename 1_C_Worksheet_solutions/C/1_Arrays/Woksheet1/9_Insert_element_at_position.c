#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size=20,i,val,indx,temp1,temp2;
    int arr[]={1,2,3,4,5};
    printf("Enter value and index to insert an element: ");
    scanf("%d %d",&val,&indx);
    for(i=indx;i<size;i++)
    {
        temp1 = arr[i];
        if(i==indx)
            arr[i] = val;
        else
            arr[i] = temp2;
        temp2 = temp1;
    }
    
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}