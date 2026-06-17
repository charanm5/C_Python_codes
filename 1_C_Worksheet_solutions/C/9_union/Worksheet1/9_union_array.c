#include <stdio.h>

union Value
{
    int i;
    float f;
    char c;
};

int main()
{
    union Value arr[3];

    arr[0].i = 100;
    arr[1].f = 25.5f;
    arr[2].c = 'A';

    printf("Element 1 (int): %d\n", arr[0].i);
    printf("Element 2 (float): %.2f\n", arr[1].f);
    printf("Element 3 (char): %c\n", arr[2].c);

    return 0;
}