#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    float marks;
};

int main() {
    struct Student s1 = {1, "Alice", 95.5};

    struct Student s2;
    s2.id = 2;
    strcpy(s2.name, "Bob");
    s2.marks = 88.0;

    struct Student s3 = {3};
    s3.marks = 72.5;

    printf("STRUCTURE EXAMPLES:\n");

    printf("s1: id=%d name=%s marks=%.2f\n", s1.id, s1.name, s1.marks);
    printf("s2: id=%d name=%s marks=%.2f\n", s2.id, s2.name, s2.marks);
    printf("s3: id=%d name=%s marks=%.2f\n\n", s3.id, s3.name, s3.marks);

    printf("ARRAY VS STRUCTURE:\n");

    int arr[3] = {10, 20, 30};
    printf("Array (same type only): %d %d %d\n", arr[0], arr[1], arr[2]);

    printf("\nSIZE OF STRUCTURE = %lu bytes\n", sizeof(struct Student));

    return 0;
}