#include <stdio.h>

int main() {
    int n, i, j, temp,max_len = 1, len = 1;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            len++;
        } else if (arr[i] == arr[i - 1]) {
            continue;
        } else {
            if (len > max_len) {
                max_len = len;
            }
            len = 1;
        }
    }

    if (len > max_len) {
        max_len = len;
    }

    printf("%d\n", max_len);

    return 0;
}