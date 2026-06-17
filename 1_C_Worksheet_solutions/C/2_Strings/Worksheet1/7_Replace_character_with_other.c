#include <stdio.h>

int main()
{
    char str[100], oldChar, newChar;
    int i;

    printf("Enter string: ");
    scanf("%s", str);
    printf("Enter the charcter to replace: ");
    scanf(" %c", &oldChar);
    printf("Enter the character to replace with: ");
    scanf(" %c", &newChar);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == oldChar)
            str[i] = newChar;
    }

    printf("%s", str);

    return 0;
}