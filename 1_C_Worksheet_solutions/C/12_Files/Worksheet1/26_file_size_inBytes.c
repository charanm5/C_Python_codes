#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];
    long size;

    printf("File name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);

    size = ftell(fp);

    fclose(fp);

    printf("Size: %ld bytes\n", size);

    return 0;
}