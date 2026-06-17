#include <stdio.h>
#include <string.h>

#define INF 100000

int main()
{
    char str1[50], str2[10], ch;

    int need[256], window[256];
    int i, j, start, minLen, startIndex, count, required;

    printf("Enter string 1: ");
    scanf(" %[^\n]", str1);

    printf("Enter string 2: ");
    scanf(" %[^\n]", str2);

    for (i = 0; i < 256; i++)
    {
        need[i] = 0;
        window[i] = 0;
    }

    required = 0;

    for (i = 0; str2[i] != '\0'; i++)
    {
        need[(unsigned char)str2[i]]++;
        if (need[(unsigned char)str2[i]] == 1)
            required++;
    }

    start = 0;
    count = 0;
    minLen = INF;
    startIndex = -1;

    for (i = 0; str1[i] != '\0'; i++)
    {
        ch = str1[i];
        window[(unsigned char)ch]++;

        if (need[(unsigned char)ch] > 0 &&
            window[(unsigned char)ch] <= need[(unsigned char)ch])
        {
            count++;
        }

        if (count == strlen(str2))
        {
            while (window[(unsigned char)str1[start]] > need[(unsigned char)str1[start]] ||
                   need[(unsigned char)str1[start]] == 0)
            {
                window[(unsigned char)str1[start]]--;
                start++;
            }

            if (i - start + 1 < minLen)
            {
                minLen = i - start + 1;
                startIndex = start;
            }
        }
    }

    if (startIndex == -1)
    {
        printf("No valid substring found\n");
    }
    else
    {
        printf("Smallest substring: ");
        for (i = startIndex; i < startIndex + minLen; i++)
            printf("%c", str1[i]);
        printf("\n");
    }

    return 0;
}