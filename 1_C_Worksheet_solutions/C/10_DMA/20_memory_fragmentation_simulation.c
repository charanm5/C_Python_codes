#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, *b, *c, *d;

    a = malloc(100 * sizeof(int));
    b = malloc(200 * sizeof(int));
    c = malloc(300 * sizeof(int));

    printf("Addresses after initial allocation:\n");
    printf("a = %p b = %p c = %p\n", a, b, c);

    free(b);

    printf("After freeing middle block (b):\n");
    printf("a = %p c = %p\n", a, c);

    d = malloc(150 * sizeof(int));

    printf("New allocation:\n");
    printf("d = %p\n", d);

    free(a);
    free(c);
    free(d);

    printf("All memory freed.\n");

    return 0;
}