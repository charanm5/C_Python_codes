#include <stdio.h>

typedef struct {
    int id;
    float value;
} Data;

void modifyByValue(Data d) {
    d.id = 999;
    d.value = 99.99;
    printf("Inside modifyByValue: id=%d value=%.2f\n", d.id, d.value);
}

void modifyByPointer(Data *d) {
    d->id = 777;
    d->value = 77.77;
}

Data createData(int id, float value) {
    Data d;
    d.id = id;
    d.value = value;
    return d;
}

int main() {
    Data d1 = {1, 10.5};
    Data d2 = {2, 20.5};

    printf("Before modification:\n");
    printf("d1: id=%d value=%.2f\n", d1.id, d1.value);
    printf("d2: id=%d value=%.2f\n\n", d2.id, d2.value);

    modifyByValue(d1);
    printf("After modifyByValue (no change in original):\n");
    printf("d1: id=%d value=%.2f\n\n", d1.id, d1.value);

    modifyByPointer(&d2);
    printf("After modifyByPointer (changes reflected):\n");
    printf("d2: id=%d value=%.2f\n\n", d2.id, d2.value);

    Data d3 = createData(500, 55.5);
    printf("Returned structure from function:\n");
    printf("d3: id=%d value=%.2f\n\n", d3.id, d3.value);

    printf("Performance Insight:\n");
    printf("Pass-by-value copies entire struct -> higher overhead.\n");
    printf("Pass-by-pointer avoids copying -> preferred in embedded systems.\n");

    printf("\nMemory check:\n");
    printf("sizeof(Data) = %lu bytes\n", sizeof(Data));

    return 0;
}