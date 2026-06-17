#include <stdio.h>

int main()
{
    char s1[20], s2[20];
    int freq[256], i;

    printf("Enter string 1: ");
    scanf(" %[^\n]", s1);

    printf("Enter string 2: ");
    scanf(" %[^\n]", s2);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; s1[i] != '\0'; i++)
        freq[(unsigned char)s1[i]]++;

    for (i = 0; s2[i] != '\0'; i++)
        freq[(unsigned char)s2[i]]--;

    for (i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            printf("False\n");
            return 0;
        }
    }

    printf("True\n");

    return 0;
}