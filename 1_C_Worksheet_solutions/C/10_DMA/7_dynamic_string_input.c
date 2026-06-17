#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[20];
    int len;
    char *ptr;
    
    printf("Enter string: ");
    scanf("%[^\n]",str);
    
    len = strlen(str);
    
    ptr = (char*)malloc(len);
    
    strcpy(ptr, str);
    
    printf("%s\n",ptr);
    
    free(ptr);
   
   return 0;
}