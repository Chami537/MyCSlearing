#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct queue
{
    node *head;
    node *tail;
} queue;
node *createnewnode(int k)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = k;
    newnode->next = NULL;
    return newnode;
}
void enqueue(queue *q, int k)
{
    node *temp = createnewnode(k);
    if (q->tail == NULL)
    {
        q->head = temp;
        q->tail = temp;
        return;
    }
    q->tail->next = temp;
    q->tail = temp;
}
int dequeue(queue *q)
{
    if (q->head == NULL)
    {
        printf("no element in queue!");
        return 0;
    }
    int k = q->head->data;
    q->head = q->head->next;

    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    return k;
}
int isempty(queue *q)
{
    if (q->head == NULL)
    {
        return 1;
    }
    return 0;
}