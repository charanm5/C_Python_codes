#include <stdio.h>
#include <dirent.h>

int main() {
    char dirname[100];
    DIR *dir;
    struct dirent *entry;

    printf("Directory: ");
    scanf("%s", dirname);

    dir = opendir(dirname);

    if (dir == NULL) {
        printf("Unable to open directory.\n");
        return 1;
    }

    printf("Files:\n");

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (entry->d_name[0] == '.')
            continue;

        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}