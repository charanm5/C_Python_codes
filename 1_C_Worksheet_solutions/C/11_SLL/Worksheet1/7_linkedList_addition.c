#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;

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

void add_result(int data)
{
    struct node *temp = head3, *new;

    new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if(head3 == NULL)
        head3 = new;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }
}

void add_lists()
{
    struct node *t1 = head1;
    struct node *t2 = head2;
    int carry = 0, sum;

    while(t1 != NULL || t2 != NULL || carry != 0)
    {
        sum = carry;

        if(t1 != NULL)
        {
            sum += t1->data;
            t1 = t1->next;
        }

        if(t2 != NULL)
        {
            sum += t2->data;
            t2 = t2->next;
        }

        carry = sum / 10;
        add_result(sum % 10);
    }
}

void print_list(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    add_node1(8);
    add_node1(7);
    add_node1(9);
    add_node1(2);

    add_node2(2);
    add_node2(1);
    add_node2(2);
    add_node2(3);

    add_lists();

    printf("Result:\n");
    print_list(head3);

    return 0;
}