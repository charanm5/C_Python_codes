#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10, b = 20;
    float x = 2.5f, y = 5.5f;
    char c1 = 'A', c2 = 'B';

    int *ip = (int *)malloc(2 * sizeof(int));
    float *fp = (float *)malloc(2 * sizeof(float));
    char *cp = (char *)malloc(2 * sizeof(char));

    int *pint = &a;
    float *pfloat = &x;
    char *pchar = &c1;

    if (ip == NULL || fp == NULL || cp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    ip[0] = a;
    ip[1] = b;

    fp[0] = x;
    fp[1] = y;

    cp[0] = c1;
    cp[1] = c2;

    printf("Using allocated memory:\n");

    printf("int: %d %d\n", *(ip), *(ip + 1));
    printf("float: %f %f\n", *(fp), *(fp + 1));
    printf("char: %c %c\n", *(cp), *(cp + 1));


    printf("\nUsing direct variable addresses:\n");

    printf("int: %d\n", *pint);
    printf("float: %f\n", *pfloat);
    printf("char: %c\n", *pchar);

    printf("\nPointer arithmetic demonstration:\n");

    printf("ip[0] = %d, ip[1] = %d\n", *(ip), *(ip + 1));
    printf("fp[0] = %f, fp[1] = %f\n", *(fp), *(fp + 1));
    printf("cp[0] = %c, cp[1] = %c\n", *(cp), *(cp + 1));

    free(ip);
    free(fp);
    free(cp);

    return 0;
}