#include <stdio.h>

void increment(int *value) {
    (*value)++;
}

void doubleValue(int *value) {
    (*value) *= 2;
}

void processArray(int arr[], int size, void (*callback)(int *)) {
    for (int i = 0; i < size; i++) {
        callback(&arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    processArray(arr1, size, increment);
    printf("After increment: ");
    printArray(arr1, size);

    processArray(arr2, size, doubleValue);
    printf("After doubleValue: ");
    printArray(arr2, size);

    return 0;
}