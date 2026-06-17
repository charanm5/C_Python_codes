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

void create_loop()
{
    struct node *temp = head1;
    struct node *loop_node = NULL;

    while(temp->next != NULL)
    {
        if(temp->data == 2)
            loop_node = temp;

        temp = temp->next;
    }

    /* Last node points to node containing 2 */
    temp->next = loop_node;
}

void detect_and_remove_loop()
{
struct node *temp = head1;

while(temp != NULL)
{
    struct node *ptr = temp->next;
    struct node *check = head1;

    while(check != temp)
    {
        if(ptr == check)
        {
            printf("Loop detected\n");
            temp->next = NULL;
            return;
        }
        check = check->next;
    }

    temp = temp->next;
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
    add_node1(1);
    add_node1(2);
    add_node1(3);
    add_node1(4);
    add_node1(5);

    create_loop();

    detect_and_remove_loop();

    printf("List after removal:\n");
    print_nodes();

    return 0;
}