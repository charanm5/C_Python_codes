#include <stdio.h>
#include <string.h>

int main()
{
    char str[500];
    int lastIndex[256], i, start, maxLen, len;
    unsigned char ch;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    for (i = 0; i < 256; i++)
        lastIndex[i] = -1;

    start = 0;
    maxLen = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        if (lastIndex[ch] >= start)
            start = lastIndex[ch] + 1;

        lastIndex[ch] = i;

        len = i - start + 1;

        if (len > maxLen)
            maxLen = len;
    }

    printf("Length of longest substring: %d\n", maxLen);

    return 0;
}