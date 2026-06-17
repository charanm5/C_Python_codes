#include <stdio.h>

int main()
{
    char word[10], list[10][10];
    int n, i, j, k, ok;
    int freqWord[256], freqStr[256];

    printf("Enter word: ");
    scanf(" %[^\n]", word);

    printf("Enter number of strings: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter string %d: ", i + 1);
        scanf(" %[^\n]", list[i]);
    }

    for (i = 0; i < 256; i++)
        freqWord[i] = 0;

    for (i = 0; word[i] != '\0'; i++)
        freqWord[(unsigned char)word[i]]++;

    printf("Output: ");

    for (i = 0; i < n; i++)
    {
        for (k = 0; k < 256; k++)
            freqStr[k] = 0;

        for (j = 0; list[i][j] != '\0'; j++)
            freqStr[(unsigned char)list[i][j]]++;

        ok = 1;

        for (k = 0; k < 256; k++)
        {
            if (freqWord[k] > 0 && freqStr[k] < freqWord[k])
            {
                ok = 0;
                break;
            }
        }

        if (ok)
            printf("\"%s\" ", list[i]);
    }

    printf("\n");

    return 0;
}