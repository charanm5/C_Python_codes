#include <stdio.h>

union Data
{
    struct
    {
        int x, y;
    } point;
    int num;
};

int main()
{
    union Data data;

    data.point.x = 10;
    data.point.y = 20;

    printf("x = %d\n", data.point.x);
    printf("y = %d\n", data.point.y);

    return 0;
}