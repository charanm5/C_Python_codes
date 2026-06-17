#include <stdio.h>
#include <math.h>

double power(double a, double b) {
    return pow(a, b);
}

double modulo(double a, double b) {
    return (int)a % (int)b;
}

double squareRoot(double a, double b) {
    return sqrt(a);
}

int main() {
    double (*operations[3])(double, double) = {
        power,
        modulo,
        squareRoot
    };

    int choice;
    double num1, num2 = 0;

    printf("1. Power\n");
    printf("2. Modulo\n");
    printf("3. Square Root\n");
    printf("Choose an operation: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter base and exponent: ");
        scanf("%lf %lf", &num1, &num2);
    } else if (choice == 2) {
        printf("Enter two integers: ");
        scanf("%lf %lf", &num1, &num2);
    } else if (choice == 3) {
        printf("Enter a number: ");
        scanf("%lf", &num1);
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    double result = operations[choice - 1](num1, num2);

    printf("Result = %.2lf\n", result);

    return 0;
}