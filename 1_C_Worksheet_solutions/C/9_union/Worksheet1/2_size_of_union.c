#include <stdio.h>

union Data
{
    int i;
    double d;
    char c;
};

struct DataStruct
{
    int i;
    double d;
    char c;
};

int main()
{
    union Data u;
    struct DataStruct s;

    printf("Size of union: %zu bytes\n", sizeof(u));
    printf("Size of structure: %zu bytes\n", sizeof(s));

    return 0;
}