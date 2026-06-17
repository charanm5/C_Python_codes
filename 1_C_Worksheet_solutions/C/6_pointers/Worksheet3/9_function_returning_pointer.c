#include <stdio.h>

typedef int (*CalibArrayPtr)[10];

CalibArrayPtr get_calibration_data(void) {
    static int calibration[10] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
    return &calibration;
}

int main(void) {
    CalibArrayPtr data = get_calibration_data();

    for (int i = 0; i < 10; i++) {
        printf("%d ", (*data)[i]);
    }

    printf("\n");

    return 0;
}