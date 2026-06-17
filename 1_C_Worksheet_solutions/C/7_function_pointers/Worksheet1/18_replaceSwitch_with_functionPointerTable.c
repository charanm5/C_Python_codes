#include <stdio.h>

void create() {
    printf("Create command executed\n");
}

void read() {
    printf("Read command executed\n");
}

void update() {
    printf("Update command executed\n");
}

void deleteCmd() {
    printf("Delete command executed\n");
}

void exitCmd() {
    printf("Exit command executed\n");
}

int main() {
    void (*commands[5])() = {
        create,
        read,
        update,
        deleteCmd,
        exitCmd
    };

    int cmd;

    while (1) {
        printf("\nCommands:\n");
        printf("1. Create\n2. Read\n3. Update\n4. Delete\n5. Exit\n");
        printf("Enter command number: ");
        scanf("%d", &cmd);

        if (cmd < 1 || cmd > 5) {
            printf("Invalid command\n");
            continue;
        }

        commands[cmd - 1]();

        if (cmd == 5) {
            break;
        }
    }

    return 0;
}