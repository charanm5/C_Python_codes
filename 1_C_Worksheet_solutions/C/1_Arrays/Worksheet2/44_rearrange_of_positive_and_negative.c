#include <stdio.h>

int main() {
    int n, i, pos = 0, neg = 0;

    scanf("%d", &n);

    int arr[n], posArr[n], negArr[n], result[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negArr[neg++] = arr[i];
        } else {
            posArr[pos++] = arr[i];
        }
    }

    int p = 0, q = 0, k = 0;

    while (p < neg && q < pos) {
        result[k++] = negArr[p++];
        result[k++] = posArr[q++];
    }

    while (p < neg) {
        result[k++] = negArr[p++];
    }

    while (q < pos) {
        result[k++] = posArr[q++];
    }

    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}