#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start = 0, end, i, j = 0;
    char result[100];

    scanf(" %[^\n]", str);

    end = strlen(str) - 1;

    while (str[start] == ' ')
        start++;

    while (end >= start && str[end] == ' ')
        end--;

    for (i = start; i <= end; i++)
        result[j++] = str[i];

    result[j] = '\0';

    printf("%s", result);

    return 0;
}