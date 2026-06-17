#include <stdio.h>
#include <string.h>

int main() {
    char str[100], word[100], temp[100];
    int i, j = 0, pos = 0, first = 1;

    scanf(" %[^\n]", str);
    scanf("%s", word);

    for (i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            temp[j++] = str[i];
        } else {
            temp[j] = '\0';

            if (strcmp(temp, word) == 0) {
                if (!first)
                    printf(", ");
                printf("%d", pos);
                first = 0;
            }

            pos += 1;
            j = 0;

            if (str[i] == '\0')
                break;
        }
    }

    return 0;
}