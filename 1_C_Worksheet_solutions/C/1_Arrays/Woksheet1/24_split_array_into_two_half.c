#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int mid = n / 2;
    printf("First half: ")

    for (int i = 0; i < mid; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSecond half: ");

    for (int i = mid; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}