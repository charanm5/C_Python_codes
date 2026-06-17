#include <stdio.h>

int main()
{
    int sensors[3][3] = {
        {100, 101, 102},
        {110, 111, 112},
        {120, 121, 122}
    };

    int *p = &sensors[0][0];
    int i;

    for (i = 0; i < 9; i++)
    {
        printf("%d ", *(p + i));
    }

    printf("\n");

    return 0;
}