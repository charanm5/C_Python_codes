#include <stdio.h>
#include <stddef.h>

#pragma pack(1)
struct Register {
    char c;
    int i;
    short s;
};
#pragma pack()

int main() {
    struct Register r;

    printf("Size of struct = %lu bytes\n", sizeof(r));

    printf("Offsets:\n");
    printf("c = %lu\n", offsetof(struct Register, c));
    printf("i = %lu\n", offsetof(struct Register, i));
    printf("s = %lu\n", offsetof(struct Register, s));

    return 0;
}