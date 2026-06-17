#include <stdio.h>

int main() {
    char filename[100];
    int result;

    printf("File name: ");
    scanf("%s", filename);

    result = remove(filename);

    if (result == 0) {
        printf("File '%s' deleted.\n", filename);
    } else {
        printf("Unable to delete file.\n");
    }

    return 0;
}