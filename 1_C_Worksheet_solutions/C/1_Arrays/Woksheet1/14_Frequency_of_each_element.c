#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size=6,i,j,k,flag,count;
    int arr[]={1,2,2,3,3,3};
    for(i=0;i<size;i++)
    {
        count = flag = 0;
        for(k=0;k<i;k++)
        {
            if(arr[i] == arr[k])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            for(j=i;j<size;j++)
            {
                if(arr[i] == arr[j]) 
                    count++;
            }
            printf("%d occurs %d times\n",arr[i],count);
        }
    }
}