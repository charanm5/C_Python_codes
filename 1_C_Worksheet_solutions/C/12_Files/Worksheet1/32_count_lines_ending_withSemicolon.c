#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100];
    char line[1000];
    int count = 0;

    printf("File: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        int len = strlen(line);

        if (len > 1 && line[len - 1] == '\n') {
            if (line[len - 2] == ';') {
                count++;
            }
        }

        else {
            if (len > 0 && line[len - 1] == ';') {
                count++;
            }
        }
    }

    fclose(fp);

    printf("Lines ending with semicolon: %d\n", count);

    return 0;
}