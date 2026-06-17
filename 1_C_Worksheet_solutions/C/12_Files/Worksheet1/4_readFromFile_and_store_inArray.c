#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], lines[100][1000];
    int count, i;

    printf("File name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    count = 0;

    while (fgets(lines[count], sizeof(lines[count]), fp) != NULL) {
        lines[count][strcspn(lines[count], "\n")] = '\0';
        count++;
    }

    fclose(fp);

    printf("Array elements:\n");

    for (i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}