#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void add_end(int data)
{
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    if(head == NULL)
    {
        head = new;
    }
    else
    {
        struct node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}

void print_list()
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void free_list()
{
    struct node *temp1;
    while(head != NULL)
    {
        temp1 = head;
        head = temp1->next;
        free(temp1);
    }
}

int main()
{
    add_end(1);
    add_end(2);
    add_end(3);
    
    print_list();
    
    free_list();
   
   return 0;
}