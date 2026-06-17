#include <stdio.h>

int main() {
    FILE *file = fopen("lines.txt", "r");
    char ch;
    int lines = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n')
            lines++;
    }

    fclose(file);

    printf("Total lines: %d\n", lines);

    return 0;
}