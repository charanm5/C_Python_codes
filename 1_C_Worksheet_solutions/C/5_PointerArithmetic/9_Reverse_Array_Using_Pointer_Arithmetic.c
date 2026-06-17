#include<stdio.h>

void reverse_array(int* ptr,int len)
{
    int i,temp;
    for(i=0;i<len/2;i++)
    {
        temp = *(ptr+i);
        *(ptr+i) = *(ptr+(len-1)-i);
        *(ptr+(len-1)-i) = temp;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50},len=5,i;
    reverse_array(arr,len);
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
}