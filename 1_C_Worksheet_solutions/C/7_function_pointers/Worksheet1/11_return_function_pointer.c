#include <stdio.h>
#include <string.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int (*getOperation(char *name))(int, int) {
    if (strcmp(name, "add") == 0)
        return add;
    else if (strcmp(name, "subtract") == 0)
        return subtract;
    else if (strcmp(name, "multiply") == 0)
        return multiply;
    else
        return NULL;
}

int main() {
    char name[20];
    int a, b;
    int (*operation)(int, int);

    printf("Enter operation (add, subtract, multiply): ");
    scanf("%s", name);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    operation = getOperation(name);

    if (operation == NULL) {
        printf("Invalid operation\n");
        return 1;
    }

    printf("Result = %d\n", operation(a, b));

    return 0;
}