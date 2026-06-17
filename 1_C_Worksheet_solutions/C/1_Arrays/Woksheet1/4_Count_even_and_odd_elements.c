#include<stdio.h>

int main()
{
    int i,even_count=0,odd_count=0,size=5;
    int arr[] = {4,7,9,10,22};
    for(i=0;i<size;i++)
    {
        if(arr[i]%2 == 0)
            even_count++;
        else
            odd_count++;
    }
    printf("Even count = %d , Odd count = %d\n",even_count,odd_count);
}