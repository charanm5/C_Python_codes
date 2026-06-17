#include <stdio.h>

int main() {
    int n, sum, count = 0;

    scanf("%d", &n);

    int arr[n];

    printf("input array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSum: ");

    scanf("%d", &sum);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}