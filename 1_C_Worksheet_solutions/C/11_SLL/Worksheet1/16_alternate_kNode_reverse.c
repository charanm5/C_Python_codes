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

struct node* reverse_k(struct node *head, int k)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    int count = 0;

    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(head != NULL)
        head->next = curr;

    return prev;
}

struct node* reverse_alternate_k(struct node *head, int k)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *new_head = NULL;
    int flag = 1;

    while(curr != NULL)
    {
        if(flag == 1)
        {
            struct node *last = curr;
            struct node *rev_head = reverse_k(curr, k);

            if(new_head == NULL)
                new_head = rev_head;

            if(prev != NULL)
                prev->next = rev_head;

            prev = last;
            curr = last->next;
        }
        else
        {
            int count = 0;
            while(curr != NULL && count < k)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
        }

        flag = !flag;
    }

    return new_head;
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
    int i;
    for(i=1;i<=8;i++)
        add_node1(i);

    head1 = reverse_alternate_k(head1, 2);

    printf("Reversed:\n");
    print_list(head1);

    return 0;
}