#include <stdio.h>
#include <math.h>

double mySin(double x) {
    return sin(x);
}

double myCos(double x) {
    return cos(x);
}

double myTan(double x) {
    return tan(x);
}

double myLog(double x) {
    return log(x);
}

int main() {
    double (*mathFuncs[4])(double) = {mySin, myCos, myTan, myLog};

    int choice;
    double value, result;

    printf("1. sin\n");
    printf("2. cos\n");
    printf("3. tan\n");
    printf("4. log\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice\n");
        return 1;
    }

    printf("Enter value: ");
    scanf("%lf", &value);

    result = mathFuncs[choice - 1](value);

    printf("Result = %lf\n", result);

    return 0;
}