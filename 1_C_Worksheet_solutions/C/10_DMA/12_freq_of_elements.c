#include<stdio.h>
#include<stdlib.h>

#define SIZE   100
int main()
{
    int *ptr;
    int n, i, temp;
    
    ptr = calloc(SIZE, sizeof(int));
    
    printf("Enter number of values: ");
    scanf("%d",&n);
    
    printf("Enter values between 0 & 99: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp < 0 || temp > 99)
            printf("Please enter valid value\n");
        else
            ptr[temp]++;
    }
    
    for(i=0;i<SIZE;i++)
    {
        if(ptr[i] > 0)
            printf("%d = %d ",i,ptr[i]);
    }
    
    free(ptr);
    
    return 0;
    
}