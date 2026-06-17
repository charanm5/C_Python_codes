#include <stdio.h>

int main()
{
    char str[100], ch;
    int freq[256], i;

    printf("Enter string: ");
    scanf("%s", str);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];
        freq[(unsigned char)ch]++;
    }

    printf("Repeated characters: ");

    for (i = 0; i < 256; i++)
    {
        if (freq[i] > 1)
            printf("%c ", i);
    }

    printf("\n");

    return 0;
}