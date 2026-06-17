#include <stdio.h>

int isEven(int n) {
    return n % 2 == 0;
}

int isPositive(int n) {
    return n > 0;
}

int isPrime(int n) {
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int find(int arr[], int size, int (*condition)(int)) {
    for (int i = 0; i < size; i++) {
        if (condition(arr[i])) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int arr[] = {-5, -2, 0, 7, 8, 11, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice, result;

    printf("1. Find First Even Number\n");
    printf("2. Find First Positive Number\n");
    printf("3. Find First Prime Number\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = find(arr, size, isEven);
            break;
        case 2:
            result = find(arr, size, isPositive);
            break;
        case 3:
            result = find(arr, size, isPrime);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    if (result != -1)
        printf("First matching element: %d\n", result);
    else
        printf("No matching element found\n");

    return 0;
}