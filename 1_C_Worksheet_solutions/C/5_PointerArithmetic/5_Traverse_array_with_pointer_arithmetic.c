#include<stdio.h>

int main()
{
    int size=5,i;
    int arr[] = {11, 22, 33, 44, 55};
    int* ptr=arr;
    for(i=0;i<5;i++)
    {
        printf("%d ",*(ptr+i));
    }
    printf("\n");
}