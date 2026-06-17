#include<stdio.h>
int main()
{
    int count,i;
    printf("Enter the number of elements: ");
    scanf("%d",&count);
    int arr[count];
    printf("Enter the elements: ");
    for(i=0;i<count;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Elements in array are: ");
    for(i=0;i<count;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}