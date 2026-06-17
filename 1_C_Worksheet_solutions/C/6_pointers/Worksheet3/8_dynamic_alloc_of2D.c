#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int rows = 4, cols = 4;

    uint32_t **reg_block;

    reg_block = malloc(rows * sizeof(uint32_t *));

    for (int i = 0; i < rows; i++) {
        reg_block[i] = malloc(cols * sizeof(uint32_t));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            reg_block[i][j] = (i * cols) + j + 1;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%u ", *(*(reg_block + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(reg_block[i]);
    }

    free(reg_block);

    return 0;
}