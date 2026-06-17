##include<stdio.h>

int main()
{
    int i,smallest,largest,size=5;
    int arr[] = {8,3,15,6,2};
    smallest = largest = arr[0];
    for(i=1;i<size;i++)
    {
        if(smallest > arr[i])
            smallest = arr[i];
        if(largest < arr[i])
            largest = arr[i];
    }
    printf("Smallest = %d , Largest = %d\n",smallest,largest);
}