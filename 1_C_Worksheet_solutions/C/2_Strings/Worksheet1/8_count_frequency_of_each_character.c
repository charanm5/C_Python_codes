#include <stdio.h>

int main()
{
    char str[100];
    int freq[256], i;

    scanf("%s", str);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (freq[(unsigned char)str[i]] != 0)
        {
            printf("%c = %d\n", str[i], freq[(unsigned char)str[i]]);
            freq[(unsigned char)str[i]] = 0;
        }
    }

    return 0;
}