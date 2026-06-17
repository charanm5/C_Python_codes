#include<stdio.h>

int main()
{
    int size=5,i,search_element;
    int arr[] = {1,2,3,4,5};
    printf("Enter the element to find: ");
    scanf("%d",&search_element);
    for(i=0;i<size;i++)
    {
        if(arr[i] == search_element)
            break;
    }
    printf("The Element found at index : %d\n",i);
}