#include <stdio.h>

int main()
{
    char str[20];
    char result[40];
    int i, j, count;
    char ch;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    i = 0;
    j = 0;

    while (str[i] != '\0')
    {
        ch = str[i];
        count = 0;

        while (str[i] == ch)
        {
            count++;
            i++;
        }

        result[j++] = ch;

        if (count > 9)
        {
            result[j++] = (count / 10) + '0';
            result[j++] = (count % 10) + '0';
        }
        else
        {
            result[j++] = count + '0';
        }
    }

    result[j] = '\0';

    printf("Compressed string: %s\n", result);

    return 0;
}