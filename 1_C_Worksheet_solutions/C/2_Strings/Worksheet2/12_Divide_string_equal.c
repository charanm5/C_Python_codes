#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    int n, len, i, j, part_size;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    printf("Enter N: ");
    scanf("%d", &n);

    len = strlen(str);

    if (len % n != 0)
    {
        printf("String cannot be divided into %d equal parts\n", n);
        return 0;
    }

    part_size = len / n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < part_size; j++)
        {
            printf("%c", str[i * part_size + j]);
        }
        printf("\n");
    }

    return 0;
}