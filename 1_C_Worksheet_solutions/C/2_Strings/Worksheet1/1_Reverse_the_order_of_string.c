#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], *words[50], *token;
    int count = 0, i;

    scanf("%[^\n]", str);

    token = strtok(str, " ");
    while (token != NULL)
    {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    for (i = count - 1; i >= 0; i--)
    {
        printf("%s", words[i]);
        if (i > 0)
            printf(" ");
    }

    return 0;
}