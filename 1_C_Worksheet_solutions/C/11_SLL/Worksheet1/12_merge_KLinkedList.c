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

struct node* merge_two(struct node *a, struct node *b)
{
    struct node *result = NULL;

    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    if(a->data <= b->data)
    {
        result = a;
        result->next = merge_two(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge_two(a, b->next);
    }

    return result;
}

struct node* merge_k_lists(struct node **arr, int k)
{
    struct node *result = NULL;

    for(int i = 0; i < k; i++)
    {
        result = merge_two(result, arr[i]);
    }

    return result;
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
    add_node(&head1, 10);
    add_node(&head1, 20);
    add_node(&head1, 50);

    add_node(&head2, 30);
    add_node(&head2, 40);
    add_node(&head2, 60);

    add_node(&head3, 10);
    add_node(&head3, 70);
    add_node(&head3, 100);

    struct node *arr[3] = {head1, head2, head3};

    struct node *merged = merge_k_lists(arr, 3);

    printf("Merged list:\n");
    print_list(merged);

    return 0;
}