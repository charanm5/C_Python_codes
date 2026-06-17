#include <stdio.h>

void consoleLog(const char *message) {
    printf("Console Log: %s\n", message);
}

void fileLog(const char *message) {
    FILE *file = fopen("log.txt", "a");

    if (file) {
        fprintf(file, "File Log: %s\n", message);
        fclose(file);
        printf("Logged to file\n");
    } else {
        printf("File error\n");
    }
}

void networkLog(const char *message) {
    printf("Network Log: %s\n", message);
}

int main() {
    void (*logger)(const char *);
    int choice;
    char message[100];

    printf("1. Console Log\n");
    printf("2. File Log\n");
    printf("3. Network Log\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter message: ");
    scanf(" %[^\n]", message);

    if (choice == 1) {
        logger = consoleLog;
    } else if (choice == 2) {
        logger = fileLog;
    } else if (choice == 3) {
        logger = networkLog;
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    logger(message);

    printf("\nSwitching to console log...\n");
    logger = consoleLog;
    logger("Runtime switch successful");

    return 0;
}