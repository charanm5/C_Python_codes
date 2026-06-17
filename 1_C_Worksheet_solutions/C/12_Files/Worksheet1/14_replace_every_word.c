#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp, *temp;
    char filename[100], oldWord[50], newWord[50];
    char line[1000];

    printf("File name: ");
    scanf("%s", filename);

    printf("Word to replace: ");
    scanf("%s", oldWord);

    printf("Replacement: ");
    scanf("%s", newWord);

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

    while (fgets(line, sizeof(line), fp)) {
        char *pos, result[2000] = "";
        char *start = line;

        while ((pos = strstr(start, oldWord)) != NULL) {
            strncat(result, start, pos - start);
            strcat(result, newWord);
            start = pos + strlen(oldWord);
        }

        strcat(result, start);
        fputs(result, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("Replacement completed.\n");

    return 0;
}