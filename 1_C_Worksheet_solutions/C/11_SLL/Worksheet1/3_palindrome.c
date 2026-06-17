#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;

void add_node1(int data)
{
    struct node *temp = head1, *new;

    new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if(head1 == NULL)
        head1 = new;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }
}

void check_palindrome()
{
    struct node *temp = head1;
    int arr[100];
    int count = 0;

    while(temp != NULL)
    {
        arr[count++] = temp->data;
        temp = temp->next;
    }

    int i = 0, j = count - 1;

    while(i < j)
    {
        if(arr[i] != arr[j])
        {
            printf("Linked list is not a palindrome.\n");
            return;
        }

        i++;
        j--;
    }

    printf("Linked list is a palindrome.\n");
}

void print_nodes()
{
    struct node *temp = head1;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    add_node1(1);
    add_node1(2);
    add_node1(2);
    add_node1(1);

    printf("List: ");
    print_nodes();

    check_palindrome();

    return 0;
}