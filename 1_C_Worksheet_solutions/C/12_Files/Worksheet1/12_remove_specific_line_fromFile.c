#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp, *temp;
    char buffer[1000];
    int lineNo, currentLine = 1;

    printf("File name: ");
    char filename[100];
    scanf("%s", filename);

    printf("Line to remove: ");
    scanf("%d", &lineNo);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (currentLine != lineNo) {
            fputs(buffer, temp);
        }
        currentLine++;
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("File now contains all lines except line %d.\n", lineNo);

    return 0;
}