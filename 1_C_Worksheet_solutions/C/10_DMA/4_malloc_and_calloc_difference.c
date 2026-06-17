#include<stdio.h>
#include<stdlib.h>

int main()
{
    int count, i;
    int *mptr, *cptr;
    
    printf("Enter the number of integers: ");
    scanf("%d",&count);
    
    cptr = (int*)calloc(count,sizeof(int));
    if(cptr != NULL) {
        printf("Before assigning values to memory: ");
        for(i=0;i<count;i++)
        {
            printf("%d ",*(cptr+i));
        }
    }
    else
    {
        printf("calloc failed\n");
        return 1;
    }
        
    mptr = (int*)malloc(sizeof(int) * count);
    if(mptr != NULL) {
        printf("\nBefore assigning values to memory: ");
        for(i=0;i<count;i++)
        {
            printf("%d ",*(mptr+i));
        }
    }
    else
        printf("malloc failed\n");
    
    
    free(cptr);
    free(mptr);
    
    return 0;
}