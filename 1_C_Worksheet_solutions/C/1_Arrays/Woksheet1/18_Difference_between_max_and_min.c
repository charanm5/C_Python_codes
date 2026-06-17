#include<stdio.h>
int main()
{
    int arr[] = {1,2,3,4,9,8,6},len=7;
    int i,largest,smallest;
    largest=smallest=arr[0];
    for(i=0;i<len;i++)
    {
        if(largest < arr[i])
            largest = arr[i];
        if(smallest > arr[i])
            smallest = arr[i];
    }
    printf("%d is the difference\n",largest-smallest);
}