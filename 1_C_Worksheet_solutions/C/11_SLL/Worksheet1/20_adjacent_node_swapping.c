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

void swap_pairs()
{
    struct node *curr = head1;
    struct node *prev = NULL;
    struct node *first, *second;

    while(curr != NULL && curr->next != NULL)
    {
        first = curr;
        second = curr->next;

        first->next = second->next;
        second->next = first;

        if(prev == NULL)
            head1 = second;
        else
            prev->next = second;

        prev = first;
        curr = first->next;
    }
}

void print_list()
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
    add_node1(3);
    add_node1(4);
    add_node1(5);

    swap_pairs();

    printf("Swapped list:\n");
    print_list();

    return 0;
}