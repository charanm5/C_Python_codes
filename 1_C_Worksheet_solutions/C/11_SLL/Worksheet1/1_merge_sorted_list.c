#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;

void add_node1(int data)
{
    struct node *temp = head1;
    struct node *new = malloc(sizeof(struct node));

    new->data = data;
    new->next = NULL;

    if (head1 == NULL)
        head1 = new;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }
}

void add_node2(int data)
{
    struct node *temp = head2;
    struct node *new = malloc(sizeof(struct node));

    new->data = data;
    new->next = NULL;

    if (head2 == NULL)
        head2 = new;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }
}

void append_head3(struct node **tail, int val)
{
    struct node *new = malloc(sizeof(struct node));

    new->data = val;
    new->next = NULL;

    if (head3 == NULL)
    {
        head3 = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
}

void merge_sorted_nodes()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *tail = NULL;
    int val;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            val = temp1->data;
            temp1 = temp1->next;
        }
        else if (temp1->data > temp2->data)
        {
            val = temp2->data;
            temp2 = temp2->next;
        }
        else
        {
            val = temp1->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (tail == NULL || tail->data != val)
            append_head3(&tail, val);
    }

    while (temp1 != NULL)
    {
        if (tail == NULL || tail->data != temp1->data)
            append_head3(&tail, temp1->data);

        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        if (tail == NULL || tail->data != temp2->data)
            append_head3(&tail, temp2->data);

        temp2 = temp2->next;
    }
}

void print_merged_nodes()
{
    struct node *temp = head3;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    add_node1(1);
    add_node1(3);
    add_node1(5);
    add_node1(7);

    add_node2(2);
    add_node2(4);
    add_node2(6);

    merge_sorted_nodes();

    print_merged_nodes();

    return 0;
}