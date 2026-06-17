#include <stdio.h>
#include <string.h>

struct DataStruct {
    char c;
    int i;
    float f;
};

union DataUnion {
    char c;
    int i;
    float f;
};

int main() {
    struct DataStruct s;
    union DataUnion u;

    printf("Size of structure = %lu bytes\n", sizeof(s));
    printf("Size of union = %lu bytes\n\n", sizeof(u));

    s.c = 'A';
    s.i = 100;
    s.f = 3.14f;

    printf("STRUCTURE VALUES:\n");
    printf("c = %c\n", s.c);
    printf("i = %d\n", s.i);
    printf("f = %f\n\n", s.f);

    u.c = 'A';
    printf("UNION after setting char: c=%c i=%d f=%f\n", u.c, u.i, u.f);

    u.i = 100;
    printf("UNION after setting int: c=%c i=%d f=%f\n", u.c, u.i, u.f);

    u.f = 3.14f;
    printf("UNION after setting float: c=%c i=%d f=%f\n\n", u.c, u.i, u.f);

    unsigned char buffer[sizeof(union DataUnion)];
    memcpy(buffer, &u, sizeof(u));

    printf("BYTE BUFFER VIEW:\n");
    for (int i = 0; i < (int)sizeof(u); i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n\n");

    return 0;
}