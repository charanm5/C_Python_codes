#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char file1[100], file2[100];
    int ch1, ch2;

    printf("File1: ");
    scanf("%s", file1);

    printf("File2: ");
    scanf("%s", file2);

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (1) {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ch1 != ch2) {
            printf("Files are different\n");
            fclose(fp1);
            fclose(fp2);
            return 0;
        }

        if (ch1 == EOF && ch2 == EOF) {
            break;
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Files are identical\n");

    return 0;
}