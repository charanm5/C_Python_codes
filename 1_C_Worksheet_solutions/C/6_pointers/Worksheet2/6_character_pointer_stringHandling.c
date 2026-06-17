#include <stdio.h>
#include <stdlib.h>

int strLength(char *p)
{
    int len = 0;
    while (*p != '\0')
    {
        len++;
        p++;
    }
    return len;
}

void strCopy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void strConcat(char *dest, char *src)
{
    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

void strReverse(char *str)
{
    char *start = str;
    char *end = str;

    char temp;

    while (*end != '\0')
    {
        end++;
    }
    end--;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main()
{
    char *str = (char *)malloc(50 * sizeof(char));
    char *str2 = (char *)malloc(50 * sizeof(char));

    if (str == NULL || str2 == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    strCopy(str, "Hello");
    strCopy(str2, "World");

    printf("String 1: %s\n", str);
    printf("String 2: %s\n", str2);

    strConcat(str, " ");
    strConcat(str, str2);

    printf("Concatenated: %s\n", str);

    printf("Length: %d\n", strLength(str));

    strReverse(str);
    printf("Reversed: %s\n", str);

    free(str);
    free(str2);

    return 0;
}