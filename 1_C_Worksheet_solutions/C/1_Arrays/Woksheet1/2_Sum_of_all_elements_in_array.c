#include<stdio.h>
int main()
{
    int count,i,sum=0;
    printf("Enter the number of elements: ");
    scanf("%d",&count);
    int arr[count];
    printf("Enter the elements: ");
    for(i=0;i<count;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("Sum = %d\n",sum);
}