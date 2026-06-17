#include <stdio.h>

int main() {
    int n, k, i, j, sum, max_sum;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    max_sum = 0;

    for (i = 0; i <= n - k; i++) {
        sum = 0;

        for (j = i; j < i + k; j++) {
            sum += arr[j];
        }

        if (i == 0 || sum > max_sum) {
            max_sum = sum;
        }
    }

    printf("%d\n", max_sum);

    return 0;
}