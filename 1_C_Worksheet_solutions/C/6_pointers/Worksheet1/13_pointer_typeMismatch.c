#include <stdio.h>

int main()
{
    int a = 10;
    int *ip = &a;
    float *fp;

    fp = (float *)ip;

    printf("ip points to int a = %d\n", *ip);
    printf("fp (casted) dereference = %f\n", *fp);

    return 0;
}