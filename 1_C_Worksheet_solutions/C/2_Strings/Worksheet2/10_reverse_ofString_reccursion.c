#include <stdio.h>

void reverse(char str[], int i)
{
    if (str[i] == '\0')
        return;

    reverse(str, i + 1);
    printf("%c", str[i]);
}

int main()
{
    char str[20];

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    printf("Reversed string: ");

    reverse(str, 0);

    printf("\n");

    return 0;
}