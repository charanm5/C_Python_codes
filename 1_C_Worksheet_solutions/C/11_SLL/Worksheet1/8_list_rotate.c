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

int get_length()
{
    struct node *temp = head1;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void rotate_right(int k)
{
    if(head1 == NULL || k == 0)
        return;

    int len = get_length();

    k = k % len;
    if(k == 0)
        return;

    struct node *temp = head1;
    struct node *prev = NULL;

    int steps = len - k;

    for(int i = 0; i < steps; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    struct node *new_head = temp;
    prev->next = NULL;

    struct node *tail = new_head;

    while(tail->next != NULL)
        tail = tail->next;

    tail->next = head1;

    head1 = new_head;
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
    add_node1(3);
    add_node1(4);
    add_node1(7);
    add_node1(9);

    rotate_right(2);

    printf("Rotated list:\n");
    print_list();

    return 0;
}