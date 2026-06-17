#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size1=5,size2=5,i,j,size3=size1+size2;
    int arr1[]={1,2,3,4,5},arr2[]={6,7,8,9,10},merged_arr[size3];
    for(i=0;i<size1;i++)
    {
        merged_arr[i] = arr1[i];
    }
    for(j=0;j<size2;j++)
    {
        merged_arr[i] = arr2[j];
        i++;
    }
    for(i=0;i<size3;i++)
    {
        printf("%d ",merged_arr[i]);
    }
    printf("\n");
}