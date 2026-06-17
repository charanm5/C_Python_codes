#include<stdio.h>
#include<string.h>

#define SIZE 10

int main()
{
   char str1[] = "hello";
   char str2[] = "world";
   //char str2[] = "hello";
   int result = memcmp(str1,str2,sizeof(str1));
   if(result == 0)
    printf("same character arrays\n");
   else if(result < 0)
    printf("str2 is greater\n");
   else 
    printf("str1 is greater\n");
}