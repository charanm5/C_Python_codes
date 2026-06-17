#include <stdio.h>

void buttonPressHandler() {
    printf("Button Press Event Handled\n");
}

void sensorTriggerHandler() {
    printf("Sensor Trigger Event Handled\n");
}

int main() {
    void (*eventHandlers[2])() = {
        buttonPressHandler,
        sensorTriggerHandler
    };

    int event;

    while (1) {
        printf("\nEvents:\n");
        printf("1. Button Press Event\n");
        printf("2. Sensor Trigger Event\n");
        printf("0. Exit\n");
        printf("Enter event number: ");
        scanf("%d", &event);

        if (event == 0) {
            break;
        }

        if (event >= 1 && event <= 2) {
            eventHandlers[event - 1]();
        } else {
            printf("Invalid Event\n");
        }
    }

    return 0;
}