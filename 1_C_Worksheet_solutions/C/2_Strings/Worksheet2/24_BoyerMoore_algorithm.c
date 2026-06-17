#include <stdio.h>
#include <string.h>

#define ALPHABET 256

int main()
{
    char text[50];
    char pattern[20];
    int badChar[ALPHABET];

    int n, m, i, j, shift, found;

    printf("Enter text: ");
    scanf(" %[^\n]", text);

    printf("Enter pattern: ");
    scanf(" %[^\n]", pattern);

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i < ALPHABET; i++)
        badChar[i] = -1;

    for (i = 0; i < m; i++)
        badChar[(unsigned char)pattern[i]] = i;

    shift = 0;
    found = 0;

    while (shift <= n - m)
    {
        j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0)
        {
            printf("Pattern found at index %d\n", shift);
            found = 1;
            break;
        }
        else
        {
            shift += (j - badChar[(unsigned char)text[shift + j]]);
            if (shift < 0)
                shift = shift + 1;
        }
    }

    if (!found)
        printf("Pattern not found\n");

    return 0;
}