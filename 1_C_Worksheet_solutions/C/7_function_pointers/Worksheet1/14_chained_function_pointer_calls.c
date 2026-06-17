#include <stdio.h>

int doubleValue(int x) {
    return x * 2;
}

int increment(int x) {
    return x + 1;
}

int square(int x) {
    return x * x;
}

int main() {
    int (*pipeline[])(int) = {
        doubleValue,
        increment,
        square
    };

    int n;
    int size = sizeof(pipeline) / sizeof(pipeline[0]);

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i < size; i++) {
        n = pipeline[i](n);
    }

    printf("Final result = %d\n", n);

    return 0;
}#include <stdio.h>

int doubleValue(int x) {
    return x * 2;
}

int increment(int x) {
    return x + 1;
}

int square(int x) {
    return x * x;
}

int main() {
    int (*pipeline[])(int) = {
        doubleValue,
        increment,
        square
    };

    int n;
    int size = sizeof(pipeline) / sizeof(pipeline[0]);

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i < size; i++) {
        n = pipeline[i](n);
    }

    printf("Final result = %d\n", n);

    return 0;
}