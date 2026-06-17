#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isBlankLine(char line[]) {
    int i = 0;

    // Skip spaces and tabs
    while (line[i] != '\0') {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return 0;
        i++;
    }

    return 1;
}

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
        if (isBlankLine(line)) {
            count++;
        }
    }

    fclose(fp);

    printf("Blank lines: %d\n", count);

    return 0;
}