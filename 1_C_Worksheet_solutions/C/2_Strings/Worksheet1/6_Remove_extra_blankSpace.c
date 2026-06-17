#include <stdio.h>

int main()
{
    char str[100], result[100];
    int i, j = 0, start, end;

    scanf("%[^\n]", str);

    start = 0;
    while (str[start] == ' ')
        start++;

    end = 0;
    while (str[end] != '\0')
        end++;
    end--;

    while (end >= 0 && str[end] == ' ')
        end--;

    for (i = start; i <= end; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
            continue;

        result[j++] = str[i];
    }

    result[j] = '\0';

    printf("%s", result);

    return 0;
}