#include <stdio.h>

int main()
{
    char str[500];
    int i=0, count=0;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    while (str[i] != '\0')
    {
        while (str[i] == ' ')
            i++;

        if (str[i] != '\0')
        {
            count++;

            while (str[i] != ' ' && str[i] != '\0')
                i++;
        }
    }

    printf("Number of words: %d\n", count);

    return 0;
}