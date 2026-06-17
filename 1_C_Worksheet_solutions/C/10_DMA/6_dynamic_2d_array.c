#include<stdio.h>
#include<stdlib.h>

int main()
{
   int i, j, row, col;
   int **ptr;
   
   printf("Enter number of rows and columns: ");
   scanf("%d %d",&row, &col);
   
   ptr = malloc(row * sizeof(int*));
   for(i=0; i<row; i++)
   {
       ptr[i] = (int*)malloc(col * sizeof(int));
   }
   
   printf("Enter the values: ");
   for(i=0; i<row; i++)
   {
       for(j=0; j<col; j++)
       {
           scanf("%d",&ptr[i][j]);
       }
   }

   printf("Entered values are: \n");
   for(i=0; i<row; i++)
   {
       for(j=0; j<col; j++)
       {
           printf("%d ",ptr[i][j]);
       }
       printf("\n");
   }
   
   for(i=0; i<row; i++)
   {
       free(ptr[i]);
   }
   
   free(ptr);
   
   return 0;
}