#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

int main()
{
    char text[500];
    char pattern[200];

    int n, m, i, j, h, p, t, found;

    printf("Enter text: ");
    scanf(" %[^\n]", text);

    printf("Enter pattern: ");
    scanf(" %[^\n]", pattern);

    n = strlen(text);
    m = strlen(pattern);

    if (m > n)
    {
        printf("Pattern not found\n");
        return 0;
    }

    h = 1;
    p = 0;
    t = 0;
    found = 0;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
            {
                printf("Pattern found at index %d\n", i);
                found = 1;
                return 0;
            }
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }

    if (!found)
        printf("Pattern not found\n");

    return 0;
}