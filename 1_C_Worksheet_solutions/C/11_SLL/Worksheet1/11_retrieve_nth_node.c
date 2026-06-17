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

void nth_from_end(int n)
{
    struct node *fast = head1;
    struct node *slow = head1;

    for(int i = 0; i < n; i++)
    {
        if(fast == NULL)
        {
            printf("n is larger than list size\n");
            return;
        }
        fast = fast->next;
    }

    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    printf("Result:\n%d\n", slow->data);
}

int main()
{
    add_node1(1);
    add_node1(3);
    add_node1(5);
    add_node1(11);

    nth_from_end(3);

    return 0;
}