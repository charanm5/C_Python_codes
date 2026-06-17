#include<stdio.h>

int main()
{
    int arr[] = {5, 10, 15, 20, 25};
    int* ptr = arr;
    ptr++;
    ptr++;
    printf("%d\n",*ptr);
}