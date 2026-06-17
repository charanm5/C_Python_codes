#include<stdio.h>

int main()
{
    int size=5,i,count=0;
    int arr[] = {-1,2,-3,-4,5};
    for(i=0;i<size;i++)
    {
        if(arr[i] < 0)
        {
            count++;
        }
    }
    printf("The number of negative elements are: %d\n",count);
}