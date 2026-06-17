#include<stdio.h>

int main()
{
    int size=5,i;
    double arr[] = {1.1, 2.2, 3.3};
    double* ptr = arr;
    printf("%f is the second element\n",*(ptr+1));
}