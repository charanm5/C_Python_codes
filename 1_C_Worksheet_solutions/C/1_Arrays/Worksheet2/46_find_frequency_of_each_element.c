#include <stdio.h>

int main() {
    int n, i, j, count;

    scanf("%d", &n);

    int arr[n], visited[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }

        count = 1;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1;
                count++;
            }
        }

        printf("%d %d\n", arr[i], count);
    }

    return 0;
}