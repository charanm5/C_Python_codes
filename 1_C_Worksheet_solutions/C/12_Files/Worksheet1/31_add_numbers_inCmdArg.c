#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int sum = 0;

    if (argc < 3) {
        printf("Usage: %s <output_file> <num1> <num2> ...\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    for (int i = 2; i < argc; i++) {
        sum += atoi(argv[i]);
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(fp, "%d\n", sum);

    fclose(fp);

    printf("sum.txt contains: %d\n", sum);

    return 0;
}