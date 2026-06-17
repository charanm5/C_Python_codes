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
        int found = 0;

        for (int j = 0; j < n2; j++) {
            if (a[i] == b[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%d ", a[i]);
        }
    }

    return 0;
}