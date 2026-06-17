#include <stdio.h>
#include <string.h>

int main() {
    char str[1000], word[100], temp[100];
    int i, j = 0, count = 0;

    scanf(" %[^\n]", str);
    scanf("%s", word);

    for (i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            temp[j++] = str[i];
        } else {
            temp[j] = '\0';

            if (strcmp(temp, word) == 0)
                count++;

            j = 0;

            if (str[i] == '\0')
                break;
        }
    }

    printf("%d", count);

    return 0;
}