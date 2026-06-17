#include <stdio.h>

int main() {
    int n, count = 0;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int prime = 1;

        if (num < 2) {
            prime = 0;
        } else {
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    prime = 0;
                    break;
                }
            }
        }

        if (prime) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}