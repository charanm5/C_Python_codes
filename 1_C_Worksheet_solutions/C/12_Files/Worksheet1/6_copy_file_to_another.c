#include <stdio.h>

int main() {
    FILE *source, *destination;
    char sourceFile[100], destinationFile[100], ch;

    printf("Source file: ");
    scanf("%s", sourceFile);

    printf("Destination file: ");
    scanf("%s", destinationFile);

    source = fopen(sourceFile, "r");

    if (source == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    destination = fopen(destinationFile, "w");

    if (destination == NULL) {
        printf("Unable to create destination file.\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File '%s' copied to '%s'.\n", sourceFile, destinationFile);

    return 0;
}