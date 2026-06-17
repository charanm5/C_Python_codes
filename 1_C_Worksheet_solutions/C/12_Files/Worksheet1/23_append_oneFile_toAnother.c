#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char file1[100], file2[100];
    int ch;

    printf("File1: ");
    scanf("%s", file1);

    printf("File2: ");
    scanf("%s", file2);

    fp1 = fopen(file1, "a"); 
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp1);
    }

    fclose(fp1);
    fclose(fp2);

    printf("File2 appended to File1 successfully.\n");

    return 0;
}