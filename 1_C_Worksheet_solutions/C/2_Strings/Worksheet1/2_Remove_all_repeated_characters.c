#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, len, found;

    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        found = 0;

        for (j = 0; j < i; j++)
        {
            if (str[i] == str[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
            printf("%c", str[i]);
    }

    return 0;
}