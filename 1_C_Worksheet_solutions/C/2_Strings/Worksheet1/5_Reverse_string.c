#include <stdio.h>

int main()
{
    char str[100], temp;
    int i, len = 0;

    scanf("%s", str);

    while (str[len] != '\0')
        len++;

    for (i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("%s", str);

    return 0;
}