#include <stdio.h>

int main() {
    char str[1000], oldChar, newChar;
    int i;

    scanf("%s", str);
    scanf(" %c %c", &oldChar, &newChar);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
            break;
        }
    }

    printf("%s", str);

    return 0;
}