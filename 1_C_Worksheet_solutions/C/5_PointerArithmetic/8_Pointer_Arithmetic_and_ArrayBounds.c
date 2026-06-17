#include<stdio.h>

int main()
{
    int arr[] = {10, 20, 30};
    int *ptr = arr; // Out of bounds
    printf("%d \n",*(ptr+5));
}