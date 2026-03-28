#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *createnewnode(int k)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = k;
    newnode->next = NULL;
    return newnode;
}
// 尾插节点
Node *buildlist(int arr[], int n)
{
    Node *head = createnewnode(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp1 = createnewnode(arr[i]);
        temp->next = temp1;
        temp = temp->next;
    }
    return head;
}
// 打印
void printlist(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        printf("%d->", temp->data);

        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
}
int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
// 删除指定节点
Node *deletenode(Node *head, int k)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != k)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("no such node");
    }
    if (temp != NULL)
    {
        if (temp == head)
        {
            return temp->next;
        }
        prev->next = temp->next;

        free(temp);
    }
    return head;
}
//
Node *reverselist(Node *head)
{
    Node *temp = head;
    if (temp == NULL || temp->next == NULL)
    {
        return temp;
    }
    Node *newhead = reverselist(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    return newhead;
}
Node *mergesortedlists(Node *l1, Node *l2)
{
    Node *temp1 = l1;
    Node *temp2 = l2;
    if (temp1 == NULL)
    {
        return temp2;
    }
    if (temp2 == NULL)
    {
        return temp1;
    }
    if (temp1->data > temp2->data)
    {
        temp2->next = mergesortedlists(temp1, temp2->next);
        return temp2;
    }
    if (temp1->data <= temp2->data)
    {
        temp1->next = mergesortedlists(temp1->next, temp2);
        return temp1;
    }
}
Node *findmiddle(Node *head)
{

    if (head == NULL)
    {
        return head;
    }
    Node *fast = head; // 跑n-1次
    Node *slow = head; // 跑n-1/2次

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
int hascycle(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) // 先左边判断
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    return 0;
}