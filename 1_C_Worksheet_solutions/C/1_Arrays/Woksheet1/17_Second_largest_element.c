#include<stdio.h>

int main()
{
    int arr[]={10,40,20,30,50},len=5,largest,secondLargest,i;
    largest=secondLargest=arr[0];
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    printf("SecondLargest = %d\n",secondLargest);
}