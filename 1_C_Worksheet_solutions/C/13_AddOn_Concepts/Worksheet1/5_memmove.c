#include <stdio.h>
#include <string.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    memmove(&arr[1], &arr[0], 4 * sizeof(int));

    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    return 0;
}