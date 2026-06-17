#include <stdio.h>
#include <string.h>

void sortChar(char str[])
{
    int i, j;
    int n = strlen(str);
    char temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main()
{
    char words[10][10] = {"cat", "tac", "act", "dog"};
    char sorted[10][10];
    int used[10];
    int n = 4, i, j;

    for (i = 0; i < n; i++)
        used[i] = 0;

    for (i = 0; i < n; i++)
    {
        strcpy(sorted[i], words[i]);
        sortChar(sorted[i]);
    }

    printf("Grouped Anagrams:\n");

    for (i = 0; i < n; i++)
    {
        if (used[i])
            continue;

        printf("[\"%s\"", words[i]);
        used[i] = 1;

        for (j = i + 1; j < n; j++)
        {
            if (strcmp(sorted[i], sorted[j]) == 0)
            {
                printf(", \"%s\"", words[j]);
                used[j] = 1;
            }
        }

        printf("]\n");
    }

    return 0;
}