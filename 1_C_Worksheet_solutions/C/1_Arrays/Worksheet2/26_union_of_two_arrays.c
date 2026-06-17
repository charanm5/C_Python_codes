#include <stdio.h>

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int a[n1];

    for (int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n2);
    int b[n2];

    for (int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n1; i++) {
        int unique = 1;

        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                unique = 0;
                break;
            }
        }

        if (unique) {
            printf("%d ", a[i]);
        }
    }

    for (int i = 0; i < n2; i++) {
        int unique = 1;

        for (int j = 0; j < n1; j++) {
            if (b[i] == a[j]) {
                unique = 0;
                break;
            }
        }

        for (int j = 0; j < i && unique; j++) {
            if (b[i] == b[j]) {
                unique = 0;
                break;
            }
        }

        if (unique) {
            printf("%d ", b[i]);
        }
    }

    return 0;
}