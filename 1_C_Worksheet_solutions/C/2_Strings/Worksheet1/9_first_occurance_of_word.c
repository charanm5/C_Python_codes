#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], word[50], temp[50];
    int i = 0, j = 0, pos = -1, k;

    scanf("%[^\n]", str);
    scanf(" %s", word);

    while (str[i] != '\0')
    {
        j = 0;
        k = i;

        while (str[k] != ' ' && str[k] != '\0')
        {
            temp[j++] = str[k];
            k++;
        }

        temp[j] = '\0';

        if (strcmp(temp, word) == 0)
        {
            pos = i;
            break;
        }

        i = k;

        while (str[i] == ' ')
            i++;
    }

    printf("Found at position %d", pos+1);

    return 0;
}