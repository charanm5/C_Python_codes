#include<stdio.h>
#include<string.h>


int main()
{
   char str1[10] = "hello";
   char str2[10];
   memcpy(str2,str1,10);
   printf("%s\n",str2);
}