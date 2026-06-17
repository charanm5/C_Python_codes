#include <stdio.h>

int main() {
    char str[1000], ch;
    int i, pos = -1;

    scanf("%s", str);
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            pos = i;
    }

    if (pos != -1)
        printf("Position: %d", pos);
    else
        printf("Character not found");

    return 0;
}