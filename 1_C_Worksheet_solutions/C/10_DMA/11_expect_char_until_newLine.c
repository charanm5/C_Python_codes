#include<stdio.h>
#include<stdlib.h>

int main()
{
    char* str;
    char ch;
    int len=0;
    
    str = malloc(sizeof(char));
    
    while((ch=getchar()) != '\n')
    {
        str = realloc(str,++len);
        *(str+(len-1)) = ch;
    }
    str = realloc(str,++len);
    *(str+len) = '\0';
    
    printf("%s\n",str);
    
    free(str);
    
    return 0;
    
}