#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[30];
    int age;
};

int compareByName(const void *a, const void *b) {
    struct Person *p1 = (struct Person *)a;
    struct Person *p2 = (struct Person *)b;
    return strcmp(p1->name, p2->name);
}

int compareByAge(const void *a, const void *b) {
    struct Person *p1 = (struct Person *)a;
    struct Person *p2 = (struct Person *)b;
    return p1->age - p2->age;
}

void printArray(struct Person arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", arr[i].name, arr[i].age);
    }
}

int main() {
    struct Person people[] = {
        {"Alice", 30},
        {"Bob", 20},
        {"Charlie", 25},
        {"David", 35}
    };

    int n = sizeof(people) / sizeof(people[0]);
    int choice;

    printf("1. Sort by Name\n");
    printf("2. Sort by Age\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        qsort(people, n, sizeof(struct Person), compareByName);
    } else if (choice == 2) {
        qsort(people, n, sizeof(struct Person), compareByAge);
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    printArray(people, n);

    return 0;
}