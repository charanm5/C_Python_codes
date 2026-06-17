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

void swap_kth(int k)
{
    int len = get_length();

    if(k > len)
        return;

    if(2 * k - 1 == len)
        return;

    struct node *x = head1;
    struct node *y = head1;

    struct node *prevX = NULL;
    struct node *prevY = NULL;

    for(int i = 1; i < k; i++)
    {
        prevX = x;
        x = x->next;
    }

    for(int i = 1; i < len - k + 1; i++)
    {
        prevY = y;
        y = y->next;
    }

    if(prevX != NULL)
        prevX->next = y;
    else
        head1 = y;

    if(prevY != NULL)
        prevY->next = x;
    else
        head1 = x;

    struct node *temp = x->next;
    x->next = y->next;
    y->next = temp;
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

    swap_kth(2);

    printf("Swapped list:\n");
    print_list();

    return 0;
}