#include <stdio.h>

struct Data
{
    int id;
    union
    {
        int i;
        float f;
        char c;
    };
};

int main()
{
    struct Data data;

    data.id = 1;

    data.i = 100;
    printf("ID: %d\n", data.id);
    printf("Integer: %d\n", data.i);

    data.f = 25.5f;
    printf("Float: %.2f\n", data.f);

    data.c = 'A';
    printf("Character: %c\n", data.c);

    return 0;
}