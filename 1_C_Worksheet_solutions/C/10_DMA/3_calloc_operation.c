#include<stdio.h>
#include<stdlib.h>

int main()
{
    int count, i;
    int *ptr;
    
    printf("Enter the number of integers: ");
    scanf("%d",&count);
    
    ptr = (int*)calloc(count,sizeof(int));
    if(ptr != NULL) {
        printf("Before assigning values to memory: ");
        for(i=0;i<count;i++)
        {
            printf("%d ",*(ptr+i));
        }
        printf("\nEnter the values: ");
        for(i=0;i<count;i++)
        {
            scanf("%d",(ptr+i));
        }
    }
    else {
        printf("calloc failed\n");
        return 1;
    }
    
    printf("After assigning values to memory: ");
    for(i=0;i<count;i++)
    {
        printf("%d ",*(ptr+i));
    }
    
    free(ptr);
    
    return 0;
}