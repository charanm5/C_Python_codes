#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    char *words[50], *token;
    int count = 0, i;

    printf("Enter a sentence: ");
    scanf(" %[^\n]", str);

    token = strtok(str, " ");

    while (token != NULL)
    {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    printf("Reversed sentence: ");

    for (i = count - 1; i >= 0; i--)
    {
        printf("%s", words[i]);
        if (i > 0)
            printf(" ");
    }

    printf("\n");

    return 0;
}