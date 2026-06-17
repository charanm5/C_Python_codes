#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    char filename[100];
    struct stat fileInfo;

    printf("File name: ");
    scanf("%s", filename);

    // Get file information
    if (stat(filename, &fileInfo) != 0) {
        printf("Unable to access file.\n");
        return 1;
    }

    // Convert modification time to readable format
    printf("Last modified: %s", ctime(&fileInfo.st_mtime));

    return 0;
}