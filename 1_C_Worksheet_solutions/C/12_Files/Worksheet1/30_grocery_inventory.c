#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    char quantity[50];
    int price;
};

void addItem() {
    FILE *fp = fopen("inventory.txt", "a");
    struct Item it;

    printf("Item name: ");
    scanf("%s", it.name);

    printf("Quantity: ");
    scanf("%s", it.quantity);

    printf("Price: ");
    scanf("%d", &it.price);

    fprintf(fp, "%s %s %d\n", it.name, it.quantity, it.price);
    fclose(fp);

    printf("Item added successfully\n");
}

void updateItem() {
    FILE *fp = fopen("inventory.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    struct Item it;
    char name[50];
    int found = 0;

    printf("Enter item name to update: ");
    scanf("%s", name);

    while (fscanf(fp, "%s %s %d", it.name, it.quantity, &it.price) != EOF) {
        if (strcmp(it.name, name) == 0) {
            found = 1;

            printf("New quantity: ");
            scanf("%s", it.quantity);

            printf("New price: ");
            scanf("%d", &it.price);
        }

        fprintf(temp, "%s %s %d\n", it.name, it.quantity, it.price);
    }

    fclose(fp);
    fclose(temp);

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found)
        printf("Item updated successfully\n");
    else
        printf("Item not found\n");
}

void removeItem() {
    FILE *fp = fopen("inventory.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    struct Item it;
    char name[50];
    int found = 0;

    printf("Enter item name to remove: ");
    scanf("%s", name);

    while (fscanf(fp, "%s %s %d", it.name, it.quantity, &it.price) != EOF) {
        if (strcmp(it.name, name) == 0) {
            found = 1;
            continue;
        }
        fprintf(temp, "%s %s %d\n", it.name, it.quantity, it.price);
    }

    fclose(fp);
    fclose(temp);

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found)
        printf("Item removed successfully\n");
    else
        printf("Item not found\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Grocery Inventory System ---\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Remove Item\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}