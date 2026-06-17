#include <stdio.h>

int factorial(int n, int (*self)(int, int (*) (int))) {
    if (n <= 1)
        return 1;
    return n * self(n - 1, self);
}

int fib(int n, int (*self)(int, int (*)(int))) {
    if (n <= 1)
        return n;
    return self(n - 1, self) + self(n - 2, self);
}

int main() {
    int choice, n;

    printf("1. Factorial\n2. Fibonacci\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter number: ");
    scanf("%d", &n);

    if (choice == 1) {
        int (*func)(int, int (*)(int, int (*)(int))) = factorial;
        printf("Result = %d\n", func(n, func));
    }
    else if (choice == 2) {
        int (*func)(int, int (*)(int, int (*)(int))) = fib;
        printf("Result = %d\n", func(n, func));
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}