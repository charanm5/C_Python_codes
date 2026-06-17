#include <stdio.h>
#include <stdlib.h>

int *allocate_buffer(void) {
    int *buf = (int *)malloc(10 * sizeof(int));
    return buf;
}

int main(void) {
    int *ptr = allocate_buffer();

    for (int i = 0; i < 10; i++) {
        ptr[i] = i + 1;
    }

    free(ptr);

    printf("%d\n", ptr[0]);

    return 0;
}