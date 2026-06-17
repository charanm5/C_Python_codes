#include <stdio.h>
#include <string.h>

int main() {
    char str[1000], ch;
    int i, pos = -1, len;

    scanf("%s", str);
    scanf(" %c", &ch);

    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] == ch)
            pos = i;
    }

    if (pos != -1) {
        for (i = pos; i < len; i++)
            str[i] = str[i + 1];
    }

    printf("%s", str);

    return 0;
}