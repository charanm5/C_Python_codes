#include <stdio.h>

int match(char *pattern, char *str)
{
    if (*pattern == '\0' && *str == '\0')
        return 1;

    if (*pattern == '*')
    {
        return match(pattern + 1, str) || (*str && match(pattern, str + 1));
    }

    if (*pattern == '?' || *pattern == *str)
    {
        return (*str && match(pattern + 1, str + 1));
    }

    return 0;
}

int main()
{
    char pattern[20];
    char str[20];

    printf("Enter pattern: ");
    scanf(" %[^\n]", pattern);

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    if (match(pattern, str))
        printf("Match\n");
    else
        printf("No Match\n");

    return 0;
}