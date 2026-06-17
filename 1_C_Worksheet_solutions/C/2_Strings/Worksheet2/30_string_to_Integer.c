#include <stdio.h>

int main()
{
    char str[200];
    int i=0, num=0, sign=1;

    printf("Enter numeric string: ");
    scanf(" %[^\n]", str);

    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    num = num * sign;

    printf("Integer value: %d\n", num);

    return 0;
}