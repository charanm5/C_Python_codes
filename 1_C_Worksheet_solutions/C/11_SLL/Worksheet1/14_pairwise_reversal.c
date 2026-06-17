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

void reverse_pairs()
{
    struct node *temp = head1;
    struct node *next1, *next2;
    struct node *prev = NULL;

    while(temp != NULL && temp->next != NULL)
    {
        next1 = temp;
        next2 = temp->next;

        next1->next = next2->next;
        next2->next = next1;

        if(prev == NULL)
            head1 = next2;
        else
            prev->next = next2;

        prev = next1;
        temp = next1->next;
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

    reverse_pairs();

    printf("Reversed in pairs:\n");
    print_list();

    return 0;
}