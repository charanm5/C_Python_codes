#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    
    ptr = (int*)malloc(sizeof(int));
    if(ptr != NULL)
        *ptr = 5;
    else
        printf("malloc failed\n");
    
    printf("%d\n",*ptr);
    
    if(ptr != NULL)
        free(ptr);
    
    return 0;
}