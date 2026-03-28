#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *createanewnode(int k)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = k;
    newnode->next = NULL;
    return newnode;
}
void push(int k, node **top)
{
    node *newtop = createanewnode(k);
    newtop->next = *top;
    *top = newtop; // 更新链表头
}
int pop(node **top)
{
    if ((*top) == NULL)
    {
        printf("no element!\n");
        return 0;
    }
    int a = (*top)->data;
    *top = (*top)->next;
    return a;
}
int peek(node *top)
{
    if (top == NULL)
    {
        printf("no element!\n");
        return 0;
    }
    return top->data;
}
int isempty(node *top)
{
    if (top == NULL)
    {
        return 1; // 空返回1
    }
    return 0;
}
typedef struct Queue
{
    node *inbox; // 入栈队列的栈顶指针
    node *outbox;
} Queue;
void enqueue(Queue *q, int k)
{
    push(k, &(q->inbox)); // 要的是栈顶指针的地址所以用&取一下地址
}
// 辅助函数反转一个栈,返回栈顶指针
node *reversestack(node *outbox)
{
    node *temp = outbox;
    if (temp == NULL || temp->next == NULL)
    {
        return temp;
    }
    node *newhead = reversestack(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    return newhead;
}
int dequeue(Queue *q)
{
    if (isempty(q->outbox) == 0)
    {
        return pop(&(q->outbox));
    }
    else
    {
        q->outbox = reversestack(q->inbox);
        q->inbox = NULL;
        return pop(&(q->outbox));
    }
}
