#include <stdio.h>
#include <string.h>

void removeAdj(char str[], int i, int j)
{
    if (str[i] == '\0')
    {
        str[j] = '\0';
        return;
    }

    if (j == 0 || str[i] != str[j - 1])
    {
        str[j] = str[i];
        removeAdj(str, i + 1, j + 1);
    }
    else
    {
        while (str[i] != '\0' && str[i] == str[j - 1])
            i++;

        removeAdj(str, i, j - 1);
    }
}

int main()
{
    char str[20];

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    removeAdj(str, 0, 0);

    printf("Result: %s\n", str);

    return 0;
}