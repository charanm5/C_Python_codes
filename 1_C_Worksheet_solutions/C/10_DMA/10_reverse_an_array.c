#include<stdio.h>
#include<stdlib.h>

void reverse(int* ptr, int len)
{
    int *temp_ptr;
    int temp;
    
    temp_ptr = ptr + (len-1);
    
    while(ptr<temp_ptr)
    {
        temp = *(ptr);
        *ptr = *temp_ptr;
        *temp_ptr = temp;
        ptr++;
        temp_ptr--;
        
    }
}

int main()
{
    int count;
    int *ptr,i;
    
    printf("Enter number of integers: ");
    scanf("%d",&count);
    
    ptr = malloc(count * sizeof(int));
    printf("Enter the values: ");
    for(i=0;i<count;i++)
        scanf("%d",(ptr+i));
   
    printf("Before reversing: ");
    for(i=0;i<count;i++)
        printf("%d ",*(ptr+i)); 
        
    reverse(ptr,count);
    
    printf("\nAfter reversing: ");
    for(i=0;i<count;i++)
        printf("%d ",*(ptr+i));
        
    free(ptr);
    
    return 0;
    
}