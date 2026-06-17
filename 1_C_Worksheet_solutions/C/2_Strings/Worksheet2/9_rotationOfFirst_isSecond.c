#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20], str2[20], temp[40];
    int len1, len2;

    printf("Enter string 1: ");
    scanf(" %[^\n]", str1);

    printf("Enter string 2: ");
    scanf(" %[^\n]", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 != len2)
    {
        printf("No\n");
        return 0;
    }

    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2) != NULL)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}