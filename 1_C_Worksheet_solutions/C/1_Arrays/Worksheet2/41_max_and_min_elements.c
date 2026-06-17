#include <stdio.h>

int main() {
    int n, i, max, min;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n % 2 == 0) {
        if (arr[0] < arr[1]) {
            min = arr[0];
            max = arr[1];
        } else {
            min = arr[1];
            max = arr[0];
        }
        i = 2;
    } else {
        min = max = arr[0];
        i = 1;
    }

    while (i < n - 1) {
        if (arr[i] < arr[i + 1]) {
            if (arr[i] < min) 
                min = arr[i];
            if (arr[i + 1] > max) 
                max = arr[i + 1];
        } else {
            if (arr[i + 1] < min) 
                min = arr[i + 1];
            if (arr[i] > max) 
                max = arr[i];
        }
        i += 2;
    }

    printf("%d %d\n", min, max);

    return 0;
}