#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100], line[1000];
    int n, i;

    printf("File name: ");
    scanf("%s", filename);

    printf("Number of lines: ");
    scanf("%d", &n);

    getchar();

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    printf("Lines:\n");
    for (i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);
        fputs(line, fp);
    }

    fclose(fp);

    printf("All lines saved in '%s'.\n", filename);

    return 0;
}