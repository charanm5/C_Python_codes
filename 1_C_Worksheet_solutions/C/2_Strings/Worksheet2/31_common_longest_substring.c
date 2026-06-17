#include <stdio.h>
#include <string.h>

int main()
{
    char s1[30], s2[30];
    int dp[30][30];
    int i, j, maxLen=0, endIndex=0, n, m;

    printf("Enter string 1: ");
    scanf(" %[^\n]", s1);

    printf("Enter string 2: ");
    scanf(" %[^\n]", s2);

    n = strlen(s1);
    m = strlen(s2);

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    if (maxLen == 0)
    {
        printf("No common substring\n");
        return 0;
    }

    printf("Longest common substring: ");

    for (i = endIndex - maxLen + 1; i <= endIndex; i++)
        printf("%c", s1[i]);

    printf("\n");

    return 0;
}