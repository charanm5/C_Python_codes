#include <stdio.h>
#include <stdlib.h>

void reverseString(char *start, char *end)
{
    char temp;

    if (start >= end)
        return;

    temp = *start;
    *start = *end;
    *end = temp;

    reverseString(start + 1, end - 1);
}

struct Node
{
    int data;
    struct Node *next;
};

void printRecursive(struct Node *head)
{
    if (head == NULL)
        return;

    printf("%d -> ", head->data);
    printRecursive(head->next);
}

int sumArray(int *arr, int n)
{
    if (n == 0)
        return 0;

    return *arr + sumArray(arr + 1, n - 1);
}

int main()
{
    char str[] = "HELLO";
    char *start = str;
    char *end = str;

    while (*end != '\0')
        end++;
    end--;

    reverseString(start, end);
    printf("Reversed string: %s\n", str);

    struct Node *head = NULL;
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = NULL;

    head = n1;

    printf("Linked list: ");
    printRecursive(head);
    printf("NULL\n");

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Sum of array = %d\n", sumArray(arr, n));

    free(n1);
    free(n2);
    free(n3);

    return 0;
}