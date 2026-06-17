#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* my_strdup(char *str)
{
    int len = strlen(str);
    char *ptr = (char*)malloc(len);
    int i;
    
    for(i=0;i<len;i++)
    {
        ptr[i] = str[i];
    }
    return ptr;
}

int main()
{
    char str[20];
    int len;
    char *ptr;
    
    printf("Enter string: ");
    scanf("%[^\n]",str);
    
    ptr = my_strdup(str);
    printf("%s\n",ptr);
    
    free(ptr);
   
   return 0;
}