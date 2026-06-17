#include <stdio.h>

union Sample
{
    int i;
    float f;
};

int main()
{
    union Sample s, *ptr;

    ptr = &s;

    ptr->i = 100;
    printf("Integer: %d\n", ptr->i);

    ptr->f = 25.5f;
    printf("Float: %.2f\n", ptr->f);

    return 0;
}