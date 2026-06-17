#include <stdio.h>

int main()
{
    char str[20], ch;
    int freq[256], i;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];
        freq[(unsigned char)ch]++;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (freq[(unsigned char)str[i]] == 1)
        {
            printf("First non-repeating character: '%c'\n", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character found\n");

    return 0;
}