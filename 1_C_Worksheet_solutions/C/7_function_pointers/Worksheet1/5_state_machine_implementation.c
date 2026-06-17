#include <stdio.h>

typedef void (*State)();

void initState();
void runState();
void stopState();
void errorState();

State currentState;

void initState() {
    int choice;

    printf("\nINIT STATE\n");
    printf("1. Run\n2. Error\n3. Stop\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            currentState = runState;
            break;
        case 2:
            currentState = errorState;
            break;
        case 3:
            currentState = stopState;
            break;
        default:
            currentState = errorState;
    }
}

void runState() {
    int choice;

    printf("\nRUN STATE\n");
    printf("1. Continue Running\n2. Stop\n3. Error\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            currentState = runState;
            break;
        case 2:
            currentState = stopState;
            break;
        case 3:
            currentState = errorState;
            break;
        default:
            currentState = errorState;
    }
}

void errorState() {
    int choice;

    printf("\nERROR STATE\n");
    printf("1. Reinitialize\n2. Stop\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            currentState = initState;
            break;
        case 2:
            currentState = stopState;
            break;
        default:
            currentState = stopState;
    }
}

void stopState() {
    printf("\nSTOP STATE\n");
    currentState = NULL;
}

int main() {
    currentState = initState;

    while (currentState != NULL) {
        currentState();
    }

    printf("State machine terminated.\n");

    return 0;
}