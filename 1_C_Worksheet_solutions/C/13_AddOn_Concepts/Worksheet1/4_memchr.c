#include<stdio.h>
#include<string.h>

int main()
{
   char str1[] = "hello";
   char *ptr = memchr(str1,'e',strlen(str1));
   if(ptr == NULL)
        printf("Not found\n");
   else
        printf("found at %p\n",ptr);
}