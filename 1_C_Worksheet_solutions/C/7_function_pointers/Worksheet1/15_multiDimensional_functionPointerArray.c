#include <stdio.h>

int intAdd(int a, int b) {
    return a + b;
}

int intBitwiseAnd(int a, int b) {
    return a & b;
}

float floatAdd(float a, float b) {
    return a + b;
}

float floatBitwiseAnd(float a, float b) {
    int x = (int)a;
    int y = (int)b;
    return (float)(x & y);
}

int main() {
    int (*intOps[2][2])(int, int);
    float (*floatOps[2][2])(float, float);

    intOps[0][0] = intAdd;
    intOps[0][1] = intBitwiseAnd;

    floatOps[0][0] = floatAdd;
    floatOps[0][1] = floatBitwiseAnd;

    int type, op;
    int a, b;
    float x, y;

    printf("Select type:\n");
    printf("1. int\n2. float\n");
    scanf("%d", &type);

    printf("Select operation:\n");
    printf("1. Add\n2. Bitwise AND\n");
    scanf("%d", &op);

    if (type == 1) {
        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);

        int result = intOps[0][op - 1](a, b);
        printf("Result = %d\n", result);
    }
    else if (type == 2) {
        printf("Enter two floats: ");
        scanf("%f %f", &x, &y);

        float result = floatOps[0][op - 1](x, y);
        printf("Result = %.2f\n", result);
    }
    else {
        printf("Invalid type\n");
    }

    return 0;
}