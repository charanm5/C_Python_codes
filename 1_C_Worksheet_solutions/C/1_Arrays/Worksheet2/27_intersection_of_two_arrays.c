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
        int printed = 0;

        for (int k = 0; k < i; k++) {
            if (a[i] == a[k]) {
                printed = 1;
                break;
            }
        }

        if (printed) {
            continue;
        }

        for (int j = 0; j < n2; j++) {
            if (a[i] == b[j]) {
                printf("%d ", a[i]);
                break;
            }
        }
    }

    return 0;
}