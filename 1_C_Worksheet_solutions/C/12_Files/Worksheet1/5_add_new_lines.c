#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100], line[1000];
    int n, i;

    printf("File name: ");
    scanf("%s", filename);

    printf("Number of new lines: ");
    scanf("%d", &n);

    getchar();

    fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("New lines:\n");

    for (i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);
        fputs(line, fp);
    }

    fclose(fp);

    printf("File updated successfully.\n");

    return 0;
}