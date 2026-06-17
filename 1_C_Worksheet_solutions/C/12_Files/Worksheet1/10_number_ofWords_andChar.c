#include <stdio.h>

int main() {
    FILE *file = fopen("info.txt", "r");
    char ch;
    int words = 0, characters = 0;
    int inWord = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    fclose(file);

    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}