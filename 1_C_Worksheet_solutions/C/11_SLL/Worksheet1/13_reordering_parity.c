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

void rearrange()
{
    struct node *odd_head = NULL, *odd_tail = NULL;
    struct node *even_head = NULL, *even_tail = NULL;
    struct node *temp = head1, *next;

    while(temp != NULL)
    {
        next = temp->next;
        temp->next = NULL;

        if(temp->data % 2 != 0)
        {
            if(odd_head == NULL)
                odd_head = odd_tail = temp;
            else
            {
                odd_tail->next = temp;
                odd_tail = temp;
            }
        }
        else
        {
            if(even_head == NULL)
                even_head = even_tail = temp;
            else
            {
                even_tail->next = temp;
                even_tail = temp;
            }
        }

        temp = next;
    }

    if(odd_head == NULL)
        head1 = even_head;
    else
    {
        odd_tail->next = even_head;
        head1 = odd_head;
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
    add_node1(6);

    rearrange();

    printf("Reordered list:\n");
    print_list();

    return 0;
}