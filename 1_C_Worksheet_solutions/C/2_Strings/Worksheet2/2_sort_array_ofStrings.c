#include <stdio.h>
#include <string.h>

int main() {
    char str[100][100];
    int n = 3, i, j;
    char temp[100];

    for (i = 0; i < n; i++)
        scanf("%s", str[i]);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("{");
    for (i = 0; i < n; i++) {
        printf("\"%s\"", str[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("}");

    return 0;
}