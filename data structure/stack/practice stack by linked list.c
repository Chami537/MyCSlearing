#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void printstack(node *top)
{
    while (top != NULL)
    {
        printf("%d", top->data);
        top = top->next;
    }
}
// 字符串
typedef struct charnode
{
    char data;
    struct charnode *next;
} charnode;

charnode *createnewcharnode(char c)
{
    charnode *newnode = (charnode *)malloc(sizeof(charnode));
    newnode->data = c;
    newnode->next = NULL;
    return newnode;
}

void charpush(char c, charnode **top)
{
    charnode *newtop = createnewcharnode(c);
    newtop->next = *top;
    *top = newtop;
}

char charpop(charnode **top)
{
    if (*top == NULL)
        return '\0';
    char c = (*top)->data;
    *top = (*top)->next;
    return c;
}
int isbalanced(char *str, charnode **top)
{
    char *p = str;
    while (*p != '\0')
    {
        if (*p == '(' || *p == '{' || *p == '[')
        {
            charpush(*p, top);
        }
        else if (*p == ')' || *p == '}' || *p == ']')
        {
            if (isempty(*top))
            {
                return 0;
            }
            char c = charpop(top);
            if ((*p == ')' && c != '(') || (*p == '}' && c != '{') || (*p == ']' && c != '['))
            {
                return 0;
            }
        }
        p++;
    }
    if (isempty(*top) == 0) // 栈不为空，说明有左括号没匹配
        return 0;
    return 1;
}