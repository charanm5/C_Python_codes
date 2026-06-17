#include <stdio.h>
#include <string.h>

union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;

    data.i = 100;
    printf("Integer: %d\n", data.i);

    data.f = 12.5f;
    printf("Float: %.2f\n", data.f);

    strcpy(data.str, "Hello");
    printf("String: %s\n", data.str);

    return 0;
}