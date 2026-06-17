#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    float marks;
} Student;

Student g1 = {1, "Global", 90.5};

static Student s1 = {2, "Static", 85.0};

void showStudent(Student st) {
    printf("ID=%d Name=%s Marks=%.2f\n", st.id, st.name, st.marks);
}

int main() {

    Student l1 = {3, "Local", 78.0};

    Student d1 = {
        .id = 4,
        .name = "Designated",
        .marks = 92.0
    };

    printf("GLOBAL STRUCT:\n");
    showStudent(g1);

    printf("\nSTATIC STRUCT:\n");
    showStudent(s1);

    printf("\nLOCAL STRUCT:\n");
    showStudent(l1);

    printf("\nDESIGNATED INITIALIZER STRUCT:\n");
    showStudent(d1);

    typedef struct {
        unsigned int control;
        unsigned int status;
        unsigned int data;
    } Peripheral;

    static Peripheral UART0 = {
        .control = 0x01,
        .status  = 0x00,
        .data    = 0xFF
    };

    printf("\nPERIPHERAL REGISTER (UART0):\n");
    printf("CONTROL=%u STATUS=%u DATA=%u\n",
           UART0.control, UART0.status, UART0.data);

    return 0;
}