#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

struct Calculator {
    int (*operations[3])(int, int);
};

int main() {
    struct Calculator calc;

    calc.operations[0] = add;
    calc.operations[1] = subtract;
    calc.operations[2] = multiply;

    int a, b, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("1. Add\n2. Subtract\n3. Multiply\n");
    printf("Choose operation: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice\n");
        return 1;
    }

    int result = calc.operations[choice - 1](a, b);

    printf("Result = %d\n", result);

    return 0;
}