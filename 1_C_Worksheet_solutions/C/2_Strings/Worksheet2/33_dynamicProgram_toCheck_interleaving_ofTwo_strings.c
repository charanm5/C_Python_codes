#include <stdio.h>
#include <string.h>

int main()
{
    char s1[20], s2[20], s3[40];
    int dp[20][20];
    int i, j, m, n, l;

    printf("Enter string 1: ");
    scanf(" %[^\n]", s1);

    printf("Enter string 2: ");
    scanf(" %[^\n]", s2);

    printf("Enter string 3: ");
    scanf(" %[^\n]", s3);

    n = strlen(s1);
    m = strlen(s2);
    l = strlen(s3);

    if (n + m != l)
    {
        printf("False\n");
        return 0;
    }

    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++)
            dp[i][j] = 0;

    dp[0][0] = 1;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            int k = i + j;

            if (i > 0 && s1[i - 1] == s3[k - 1] && dp[i - 1][j])
                dp[i][j] = 1;

            if (j > 0 && s2[j - 1] == s3[k - 1] && dp[i][j - 1])
                dp[i][j] = 1;
        }
    }

    if (dp[n][m])
        printf("True\n");
    else
        printf("False\n");

    return 0;
}