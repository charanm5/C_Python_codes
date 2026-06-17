#include <stdio.h>

int main() {
    int n, i;
    int product = 1;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        product = product * arr[i];
    }

    printf("%d\n", product);

    return 0;
}