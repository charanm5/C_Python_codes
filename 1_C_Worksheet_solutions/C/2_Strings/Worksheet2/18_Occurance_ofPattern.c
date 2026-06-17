#include <stdio.h>
#include <string.h>

int main()
{
    char text[20];
    char pattern[10];
    int i, j, n, m, found;

    printf("Enter text: ");
    scanf(" %[^\n]", text);

    printf("Enter pattern: ");
    scanf(" %[^\n]", pattern);

    n = strlen(text);
    m = strlen(pattern);

    printf("Pattern found at indices: ");

    found = 0;

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m)
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("Not found");

    printf("\n");

    return 0;
}