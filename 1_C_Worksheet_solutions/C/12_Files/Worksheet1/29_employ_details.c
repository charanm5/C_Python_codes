#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char name[100];
    int age;

    printf("Add new employee\n");
    printf("Name: ");
    scanf("%s", name);

    printf("Age: ");
    scanf("%d", &age);

    fp = fopen("employees.txt", "a");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(fp, "Name: %s, Age: %d\n", name, age);

    fclose(fp);

    printf("Employee added (info saved in file)\n");

    return 0;
}