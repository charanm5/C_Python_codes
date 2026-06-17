#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    int n, i, j, sum, abs_sum;
    int x, y,min_sum;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    min_sum = INT_MAX;
    x = arr[0];
    y = arr[1];

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            sum = arr[i] + arr[j];
            abs_sum = abs(sum);

            if (abs_sum < abs(min_sum)) {
                min_sum = sum;
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}