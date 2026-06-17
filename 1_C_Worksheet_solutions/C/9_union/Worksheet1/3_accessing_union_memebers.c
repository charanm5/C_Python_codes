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
    data.f = 25.5f;
    strcpy(data.str, "Hello");

    printf("Integer: %d\n", data.i);
    printf("Float: %.2f\n", data.f);
    printf("String: %s\n", data.str);

    return 0;
}