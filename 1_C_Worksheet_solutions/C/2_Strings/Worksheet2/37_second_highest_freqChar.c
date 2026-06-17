#include <stdio.h>

int main()
{
    char str[50];
    int freq[256];
    int i, max1=0, max2=0;

    char ch1, ch2;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    ch1 = ch2 = '\0';

    for (i = 0; i < 256; i++)
    {
        if (freq[i] > max1)
        {
            max2 = max1;
            ch2 = ch1;

            max1 = freq[i];
            ch1 = (char)i;
        }
        else if (freq[i] > max2 && freq[i] < max1)
        {
            max2 = freq[i];
            ch2 = (char)i;
        }
    }

    if (ch2 == '\0')
        printf("No second highest frequency character\n");
    else
        printf("Second highest frequency character: '%c'\n", ch2);

    return 0;
}