#include <stdio.h>

void timerInterrupt() {
    printf("Timer Interrupt Handled\n");
}

void keyboardInterrupt() {
    printf("Keyboard Interrupt Handled\n");
}

void errorInterrupt() {
    printf("Error Interrupt Handled\n");
}

int main() {
    void (*interruptHandlers[3])() = {
        timerInterrupt,
        keyboardInterrupt,
        errorInterrupt
    };

    int interruptNumber;

    while (1) {
        printf("\nInterrupts:\n");
        printf("1. Timer Interrupt\n");
        printf("2. Keyboard Interrupt\n");
        printf("3. Error Interrupt\n");
        printf("0. Exit\n");
        printf("Enter interrupt number: ");
        scanf("%d", &interruptNumber);

        if (interruptNumber == 0) {
            break;
        }

        if (interruptNumber >= 1 && interruptNumber <= 3) {
            interruptHandlers[interruptNumber - 1]();
        } else {
            printf("Invalid Interrupt\n");
        }
    }

    return 0;
}