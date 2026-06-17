#include<stdio.h>
#include<stdlib.h>

int main()
{
    int count, i;
    int *ptr;
    
    printf("Enter the number of integers: ");
    scanf("%d",&count);
    
    ptr = (int*)malloc(sizeof(int)*count);
    if(ptr != NULL) {
        printf("Enter the values: ");
        for(i=0;i<count;i++)
        {
            scanf("%d",(ptr+i));
        }
    }
    else
        printf("malloc failed\n");
    
    for(i=0;i<count;i++)
    {
        printf("%d ",*(ptr+i));
    }
    
    if(ptr != NULL)
        free(ptr);
    
    return 0;
}