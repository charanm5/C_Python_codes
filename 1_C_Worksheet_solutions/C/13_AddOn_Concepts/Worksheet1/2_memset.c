#include<stdio.h>
#include<string.h>

#define SIZE 10

int main()
{
   int arr[SIZE];
   memset(arr, 0, sizeof(arr));
   for(int i=0;i<SIZE;i++)
   {
       printf("%d\n",arr[i]);
   }
}