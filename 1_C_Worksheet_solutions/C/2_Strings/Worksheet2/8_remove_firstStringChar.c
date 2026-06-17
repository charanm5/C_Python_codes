#include <stdio.h>

int main()
{
    char str1[20], str2[20], result[20], ch;
    int remove[256], i , j;

    printf("Enter string 1: ");
    scanf(" %[^\n]", str1);

    printf("Enter string 2: ");
    scanf(" %[^\n]", str2);

    for (i = 0; i < 256; i++)
        remove[i] = 0;

    for (i = 0; str2[i] != '\0'; i++)
        remove[(unsigned char)str2[i]] = 1;

    j = 0;

    for (i = 0; str1[i] != '\0'; i++)
    {
        ch = str1[i];

        if (remove[(unsigned char)ch] == 0)
        {
            result[j] = ch;
            j++;
        }
    }

    result[j] = '\0';

    printf("Result: %s\n", result);

    return 0;
}