#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100];
    int ch;

    printf("File name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        fseek(fp, -1, SEEK_CUR);
        fputc(toupper(ch), fp);
        fflush(fp);
    }

    fclose(fp);

    printf("File converted to uppercase.\n");
    return 0;
}