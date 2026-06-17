#include<stdio.h>

int main()
{
    int arr[] = {11, 22, 33, 44, 55};
    int *ptr1 = &arr[2];  // points to 33
    int *ptr2 = &arr[4];  // points to 5
    printf("Pointer %s points to an earlier element\n",ptr1<ptr2?"ptr1":"ptr2");
}