#include <stdio.h>

int main() {
    FILE *file;
    int value, newValue = 100;

    file = fopen("number.txt", "r");
    fscanf(file, "%d", &value);
    fclose(file);

    printf("Read variable: %d\n", value);

    file = fopen("number.txt", "w");
    fprintf(file, "%d", newValue);
    fclose(file);

    file = fopen("number.txt", "r");
    fscanf(file, "%d", &value);
    fclose(file);

    printf("After writing value %d, file now contains: %d\n", newValue, value);

    return 0;
}