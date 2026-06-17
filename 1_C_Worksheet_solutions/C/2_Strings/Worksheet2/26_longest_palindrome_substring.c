#include <stdio.h>
#include <string.h>

int expand(char str[], int left, int right, int n)
{
    while (left >= 0 && right < n && str[left] == str[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

int main()
{
    char str[50];
    int start, end;
    int i, len, len1, len2, maxLen;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    len = strlen(str);

    start = 0;
    end = 0;

    for (i = 0; i < len; i++)
    {
        len1 = expand(str, i, i, len);
        len2 = expand(str, i, i + 1, len);

        maxLen = (len1 > len2) ? len1 : len2;

        if (maxLen > end - start + 1)
        {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    printf("Longest palindromic substring: ");

    for (i = start; i <= end; i++)
        printf("%c", str[i]);

    printf("\n");

    return 0;
}