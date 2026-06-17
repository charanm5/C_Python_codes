#include<stdio.h>
#include<stdlib.h>

int main()
{
   int i;
   int *ptr;
   ptr = calloc(2, sizeof(int));
   if(ptr != NULL)
   {
       printf("Enter 2 integer values to store: ");
       scanf("%d %d",ptr,(ptr+1));
       ptr = realloc(ptr, 5*sizeof(int));
       printf("\nExtra Memory allocated for 3 integers,Enter them: ");
       scanf("%d %d %d",(ptr+2),(ptr+3),(ptr+4));
   }
   else
   {
    printf("memory allocation failed\n");
    return 1;
   }
   
   printf("The entered values are: ");
   for(i=0;i<5;i++)
   {
       printf("%d ",*(ptr+i));
   }
   
   free(ptr);
   
   return 0;
}