#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];
    int ch;
    int key = 3;  // shift value

    printf("File name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        fseek(fp, -1, SEEK_CUR);

        ch = ch + key;

        fputc(ch, fp);
        fflush(fp);
    }

    fclose(fp);

    return 0;
}