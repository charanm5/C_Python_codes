#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char str[], int l, int r)
{
    int i;

    if (l == r)
    {
        printf("%s\n", str);
        return;
    }

    for (i = l; i <= r; i++)
    {
        swap(&str[l], &str[i]);
        permute(str, l + 1, r);
        swap(&str[l], &str[i]);
    }
}

int main()
{
    char str[10];
    int len;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    len = strlen(str);

    permute(str, 0, len - 1);

    return 0;
}