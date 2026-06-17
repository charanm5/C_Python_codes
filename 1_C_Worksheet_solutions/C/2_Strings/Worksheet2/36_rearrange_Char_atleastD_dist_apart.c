#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    int freq[256];
    int cooldown[256];
    char result[20];

    int n, i, pos;
    int maxChar, maxFreq;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    printf("Enter d: ");
    scanf("%d", &n);

    for (i = 0; i < 256; i++)
    {
        freq[i] = 0;
        cooldown[i] = 0;
    }

    for (i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    pos = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        maxFreq = 0;
        maxChar = -1;

        for (int c = 0; c < 256; c++)
        {
            if (freq[c] > 0 && cooldown[c] <= pos)
            {
                if (freq[c] > maxFreq)
                {
                    maxFreq = freq[c];
                    maxChar = c;
                }
            }
        }

        if (maxChar == -1)
        {
            printf("Not possible\n");
            return 0;
        }

        result[pos] = (char)maxChar;
        freq[maxChar]--;

        cooldown[maxChar] = pos + n;
        pos++;
    }

    result[pos] = '\0';

    printf("Rearranged string: %s\n", result);

    return 0;
}