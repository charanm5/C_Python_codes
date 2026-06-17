#include <stdio.h>
#include <string.h>

int main()
{
    char str[50], word[50], temp[50], result[50];
    int i = 0, j = 0, k, r = 0, first = 1;

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

        if (strcmp(temp, word) != 0)
        {
            if (!first)
                result[r++] = ' ';

            int x = 0;
            while (temp[x] != '\0')
                result[r++] = temp[x++];

            first = 0;
        }

        i = k;

        while (str[i] == ' ')
            i++;
    }

    result[r] = '\0';

    printf("%s", result);

    return 0;
}