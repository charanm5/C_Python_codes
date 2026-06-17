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

void add_node(struct node **head, int data)
{
    struct node *temp = *head, *new;

    new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if(*head == NULL)
        *head = new;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }
}

void merge_alternate()
{
    struct node *t1 = head1;
    struct node *t2 = head2;
    struct node *tail = NULL;
    struct node *next1, *next2;

    while(t1 != NULL || t2 != NULL)
    {
        if(t1 != NULL)
        {
            next1 = t1->next;

            if(head3 == NULL)
                head3 = tail = t1;
            else
            {
                tail->next = t1;
                tail = t1;
            }

            t1 = next1;
        }

        if(t2 != NULL)
        {
            next2 = t2->next;

            if(head3 == NULL)
                head3 = tail = t2;
            else
            {
                tail->next = t2;
                tail = t2;
            }

            t2 = next2;
        }
    }

    if(tail != NULL)
        tail->next = NULL;
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
    add_node(&head1, 9);
    add_node(&head1, 7);
    add_node(&head1, 5);

    add_node(&head2, 10);
    add_node(&head2, 8);
    add_node(&head2, 6);

    merge_alternate();

    printf("Merged list:\n");
    print_list(head3);

    return 0;
}