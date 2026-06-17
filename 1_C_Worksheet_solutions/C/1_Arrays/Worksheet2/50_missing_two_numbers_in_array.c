#include <stdio.h>

int main() {
    int n, i, j, found;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i <= n + 2; i++) {
        found = 0;

        for (j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%d ", i);
        }
    }

    return 0;
}