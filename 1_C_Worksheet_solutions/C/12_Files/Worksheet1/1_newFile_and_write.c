#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100], text[1000];

    printf("File name: ");
    scanf("%s", filename);

    getchar();

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    fprintf(fp, "%s", text);
    fclose(fp);

    printf("File '%s' created and saved.\n", filename);

    return 0;
}