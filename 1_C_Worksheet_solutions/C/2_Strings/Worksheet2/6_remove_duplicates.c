#include <stdio.h>

int main()
{
    char str[100], result[100], ch;
    int freq[256], i, j;

    printf("Enter string: ");
    scanf("%s", str);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    j = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        if (freq[(unsigned char)ch] == 0)
        {
            freq[(unsigned char)ch] = 1;
            result[j] = ch;
            j++;
        }
    }

    result[j] = '\0';

    printf("Result: %s\n", result);

    return 0;
}