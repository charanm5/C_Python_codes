#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

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

void add_node2(int data)
{
    struct node *temp = head2, *new;

    new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if(head2 == NULL)
        head2 = new;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }
}

void find_intersection()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;

    while(temp1 != temp2)
    {
        if(temp1 == NULL)
            temp1 = head2;
        else
            temp1 = temp1->next;

        if(temp2 == NULL)
            temp2 = head1;
        else
            temp2 = temp2->next;
    }

    if(temp1 != NULL)
        printf("Intersection found at node with data: %d\n", temp1->data);
    else
        printf("No intersection found\n");
}

int main()
{
    add_node1(1);
    add_node1(2);

    struct node *common1 = malloc(sizeof(struct node));
    struct node *common2 = malloc(sizeof(struct node));

    common1->data = 3;
    common2->data = 4;

    common1->next = common2;
    common2->next = NULL;

    struct node *temp = head1;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = common1;

    add_node2(5);

    head2->next = common1;

    find_intersection();

    return 0;
}