#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main()
{
    char str[50];
    int n, i, j, minCuts;
    int dp[50];

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    n = strlen(str);

    for (i = 0; i < n; i++)
        dp[i] = i;

    for (i = 0; i < n; i++)
    {
        if (isPalindrome(str, 0, i))
        {
            dp[i] = 0;
        }
        else
        {
            for (j = 0; j < i; j++)
            {
                if (isPalindrome(str, j + 1, i) && dp[j] + 1 < dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }

    minCuts = dp[n - 1] + 1;

    printf("Minimum palindromic partitions: %d\n", minCuts);

    return 0;
}