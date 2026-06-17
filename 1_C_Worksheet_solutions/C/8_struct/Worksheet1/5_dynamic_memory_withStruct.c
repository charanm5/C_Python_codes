#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (newNode == NULL) return;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void enqueue(struct Queue *q, int value) {
    struct Node *newNode = createNode(value);
    if (newNode == NULL) return;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q) {
    if (q->front == NULL) return -1;

    struct Node *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

#define POOL_SIZE 5

struct PoolNode {
    int data;
    int used;
};

struct MemoryPool {
    struct PoolNode pool[POOL_SIZE];
};

struct PoolNode *allocate(struct MemoryPool *mp, int value) {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (!mp->pool[i].used) {
            mp->pool[i].used = 1;
            mp->pool[i].data = value;
            return &mp->pool[i];
        }
    }
    return NULL;
}

void release(struct PoolNode *node) {
    if (node != NULL) {
        node->used = 0;
    }
}

int main() {
    struct Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Linked List: ");
    displayList(head);

    struct Queue q = {NULL, NULL};

    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);

    printf("Queue Dequeue: %d\n", dequeue(&q));
    printf("Queue Dequeue: %d\n", dequeue(&q));

    struct MemoryPool mp = {0};

    struct PoolNode *p1 = allocate(&mp, 5);
    struct PoolNode *p2 = allocate(&mp, 15);

    if (p1) printf("Pool1 data = %d\n", p1->data);
    if (p2) printf("Pool2 data = %d\n", p2->data);

    release(p1);

    printf("After release, Pool1 used = %d\n", p1->used);

    freeList(head);

    return 0;
}