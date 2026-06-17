#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    char result[50];
    int i=0, j=0;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    while (str[i] != '\0')
    {
        if (str[i] == 'b')
        {
            i++;
        }
        else if (str[i] == 'a' && str[i + 1] == 'c')
        {
            i += 2;
        }
        else
        {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';

    printf("Result: %s\n", result);

    return 0;
}