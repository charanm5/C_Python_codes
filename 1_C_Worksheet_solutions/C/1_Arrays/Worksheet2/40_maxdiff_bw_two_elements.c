#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_val = arr[0];
    int max_diff = arr[1] - arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] - min_val > max_diff) {
            max_diff = arr[i] - min_val;
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    printf("%d\n", max_diff);

    return 0;
}