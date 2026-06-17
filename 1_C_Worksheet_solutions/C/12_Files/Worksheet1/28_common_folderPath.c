#include <stdio.h>
#include <string.h>

#define MAX 100
#define PATHS 10

int main() {
    char paths[PATHS][MAX];
    char common[MAX];
    int n, i, j;

    printf("Number of paths: ");
    scanf("%d", &n);

    getchar(); // clear newline

    printf("Enter paths:\n");
    for (i = 0; i < n; i++) {
        fgets(paths[i], MAX, stdin);

        // remove newline
        paths[i][strcspn(paths[i], "\n")] = '\0';
    }

    // copy first path as base
    strcpy(common, paths[0]);

    for (i = 1; i < n; i++) {
        int k = 0;

        while (common[k] && paths[i][k] && common[k] == paths[i][k]) {
            k++;
        }

        common[k] = '\0'; // cut off mismatch point
    }

    // ensure we cut at folder boundary (/)
    for (i = strlen(common) - 1; i >= 0; i--) {
        if (common[i] == '/') {
            common[i] = '\0';
            break;
        }
    }

    printf("\n%s\n", common);

    return 0;
}