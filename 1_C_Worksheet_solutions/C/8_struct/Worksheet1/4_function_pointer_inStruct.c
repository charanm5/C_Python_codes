#include <stdio.h>

typedef void (*InitFunc)();
typedef void (*ReadFunc)();
typedef void (*WriteFunc)(int);

struct Driver {
    InitFunc init;
    ReadFunc read;
    WriteFunc write;
};

void sensorInit() {
    printf("Sensor Initialized\n");
}

void sensorRead() {
    printf("Sensor Data Read\n");
}

void sensorWrite(int value) {
    printf("Sensor Write Value = %d\n", value);
}

void motorInit() {
    printf("Motor Initialized\n");
}

void motorRead() {
    printf("Motor Status Read\n");
}

void motorWrite(int value) {
    printf("Motor Speed Set = %d\n", value);
}

int main() {
    struct Driver device;
    int choice, value;

    printf("Select Device Type:\n");
    printf("1. Sensor\n2. Motor\n");
    scanf("%d", &choice);

    if (choice == 1) {
        device.init = sensorInit;
        device.read = sensorRead;
        device.write = sensorWrite;
    } else {
        device.init = motorInit;
        device.read = motorRead;
        device.write = motorWrite;
    }

    device.init();
    device.read();

    printf("Enter value to write: ");
    scanf("%d", &value);

    device.write(value);

    return 0;
}