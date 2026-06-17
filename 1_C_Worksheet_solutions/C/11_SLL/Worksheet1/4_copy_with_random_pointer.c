#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *random;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void add_node1(int data)
{
    struct node *temp = head1, *new;

    new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    new->random = NULL;

    if(head1 == NULL)
        head1 = new;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }
}

void create_deep_copy()
{
    struct node *temp = head1, *new;

    while(temp != NULL)
    {
        new = malloc(sizeof(struct node));

        new->data = temp->data;
        new->random = NULL;

        new->next = temp->next;
        temp->next = new;

        temp = new->next;
    }

    temp = head1;

    while(temp != NULL)
    {
        if(temp->random != NULL)
            temp->next->random = temp->random->next;

        temp = temp->next->next;
    }

    temp = head1;
    head2 = head1->next;

    struct node *copy = head2;

    while(temp != NULL)
    {
        temp->next = copy->next;

        if(copy->next != NULL)
            copy->next = copy->next->next;

        temp = temp->next;
        copy = copy->next;
    }
}

void print_list(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("Node %d -> Random ", temp->data);

        if(temp->random != NULL)
            printf("%d\n", temp->random->data);
        else
            printf("NULL\n");

        temp = temp->next;
    }
}

int main()
{
    add_node1(1);
    add_node1(2);
    add_node1(3);
    add_node1(5);
    add_node1(7);

    struct node *n1 = head1;
    struct node *n2 = n1->next;
    struct node *n3 = n2->next;
    struct node *n5 = n3->next;
    struct node *n7 = n5->next;

    n1->random = n3;
    n2->random = n5;
    n3->random = n7;
    n5->random = n1;
    n7->random = n3;

    create_deep_copy();

    printf("Original List:\n");
    print_list(head1);

    printf("\nCopied List:\n");
    print_list(head2);

    return 0;
}