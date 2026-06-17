#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int freq[256], i, maxFreq, index;
    char maxChar;

    scanf("%s", str);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    maxFreq = 0;
    maxChar = str[0];

    for (i = 0; i < 256; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            maxChar = i;
        }
    }

    printf("'%c' appears %d times", maxChar, maxFreq);

    return 0;
}