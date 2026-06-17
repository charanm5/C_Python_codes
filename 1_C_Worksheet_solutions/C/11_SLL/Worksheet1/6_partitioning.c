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

void partition_list(int x)
{
    struct node *less_head = NULL, *less_tail = NULL;
    struct node *greater_head = NULL, *greater_tail = NULL;
    struct node *temp = head1, *next;

    while(temp != NULL)
    {
        next = temp->next;
        temp->next = NULL;

        if(temp->data < x)
        {
            if(less_head == NULL)
                less_head = less_tail = temp;
            else
            {
                less_tail->next = temp;
                less_tail = temp;
            }
        }
        else
        {
            if(greater_head == NULL)
                greater_head = greater_tail = temp;
            else
            {
                greater_tail->next = temp;
                greater_tail = temp;
            }
        }

        temp = next;
    }

    if(less_head == NULL)
        head1 = greater_head;
    else
    {
        less_tail->next = greater_head;
        head1 = less_head;
    }
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
    add_node1(3);
    add_node1(5);
    add_node1(7);
    add_node1(5);
    add_node1(9);
    add_node1(2);
    add_node1(1);

    partition_list(5);

    printf("Reordered list:\n");
    print_nodes();

    return 0;
}