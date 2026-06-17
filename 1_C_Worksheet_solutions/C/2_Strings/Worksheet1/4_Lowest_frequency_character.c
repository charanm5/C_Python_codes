#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int freq[256], i, minFreq, first;

    scanf("%s", str);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    minFreq = strlen(str);

    for (i = 0; i < 256; i++)
    {
        if (freq[i] > 0 && freq[i] < minFreq)
            minFreq = freq[i];
    }

    first = 1;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (freq[(unsigned char)str[i]] == minFreq)
        {
            if (!first)
                printf(", ");

            printf("'%c'", str[i]);
            freq[(unsigned char)str[i]] = 0;
            first = 0;
        }
    }

    printf(" each appear %d time%s", minFreq, minFreq > 1 ? "s" : "");

    return 0;
}