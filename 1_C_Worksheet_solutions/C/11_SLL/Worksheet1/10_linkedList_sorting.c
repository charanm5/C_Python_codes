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

struct node* merge(struct node *a, struct node *b)
{
    struct node *result = NULL;

    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    if(a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void split(struct node *source, struct node **front, struct node **back)
{
    struct node *slow = source;
    struct node *fast = source->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void merge_sort(struct node **head)
{
    struct node *h = *head;
    struct node *a;
    struct node *b;

    if(h == NULL || h->next == NULL)
        return;

    split(h, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *head = merge(a, b);
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
    add_node1(2);
    add_node1(3);
    add_node1(1);
    add_node1(7);
    add_node1(5);

    merge_sort(&head1);

    printf("Sorted list:\n");
    print_list();

    return 0;
}