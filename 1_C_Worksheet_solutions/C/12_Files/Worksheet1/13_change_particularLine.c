#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp, *temp;
    char filename[100];
    char buffer[1000];
    char newText[1000];
    int lineNo, currentLine = 1;

    printf("File name: ");
    scanf("%s", filename);

    printf("Line number: ");
    scanf("%d", &lineNo);
    getchar(); // consume newline left by scanf

    printf("New text: ");
    fgets(newText, sizeof(newText), stdin);

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
        if (currentLine == lineNo)
            fputs(newText, temp);
        else
            fputs(buffer, temp);

        currentLine++;
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("File now contains new text at line %d.\n", lineNo);

    return 0;
}