#include <stdio.h>

void interleave(char *s1, char *s2, char *res, int i, int j, int k)
{
    if (s1[i] == '\0' && s2[j] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", res);
        return;
    }

    if (s1[i] != '\0')
    {
        res[k] = s1[i];
        interleave(s1, s2, res, i + 1, j, k + 1);
    }

    if (s2[j] != '\0')
    {
        res[k] = s2[j];
        interleave(s1, s2, res, i, j + 1, k + 1);
    }
}

int main()
{
    char str1[10];
    char str2[10];
    char res[20];

    printf("Enter string 1: ");
    scanf(" %[^\n]", str1);

    printf("Enter string 2: ");
    scanf(" %[^\n]", str2);

    interleave(str1, str2, res, 0, 0, 0);

    return 0;
}