#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100];
    int ch;
    int newWord = 1;

    printf("File name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (newWord && isalpha(ch))
            ch = toupper(ch);

        newWord = (ch == ' ' || ch == '\n' || ch == '\t');

        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
        fflush(fp);
    }

    fclose(fp);

    printf("First letter of each word capitalized.\n");

    return 0;
}