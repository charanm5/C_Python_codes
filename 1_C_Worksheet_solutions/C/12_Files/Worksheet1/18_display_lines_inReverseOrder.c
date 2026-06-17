#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 1000

int main() {
    FILE *fp;
    char filename[100];
    char lines[MAX_LINES][MAX_LENGTH];
    int count = 0;

    printf("File name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    while (fgets(lines[count], MAX_LENGTH, fp) != NULL) {
        count++;
    }

    fclose(fp);

    printf("\nLines in reverse order:\n");
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
    }

    return 0;
}