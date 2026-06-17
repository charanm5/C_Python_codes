#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2, *fp3;
    char file1[100], file2[100], file3[100];
    char line1[1000], line2[1000];

    printf("File 1: ");
    scanf("%s", file1);

    printf("File 2: ");
    scanf("%s", file2);

    printf("New file: ");
    scanf("%s", file3);

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");
    fp3 = fopen(file3, "w");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (1) {
        int f1 = (fgets(line1, sizeof(line1), fp1) != NULL);
        int f2 = (fgets(line2, sizeof(line2), fp2) != NULL);

        if (!f1 && !f2)
            break;

        if (f1)
            fputs(line1, fp3);

        if (f2)
            fputs(line2, fp3);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Files merged alternately into %s\n", file3);

    return 0;
}