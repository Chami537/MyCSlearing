#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *creatnewnode(int k)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = k;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
} // 前序访问
void midorder(node *root)
{
    if (root == NULL)
        return;
    midorder(root->left);
    printf("%d ", root->data);
    midorder(root->right);
}
// 中序访问
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    node *head = creatnewnode(1);
    head->left = creatnewnode(2);
    head->right = creatnewnode(3);
    head->left->left = creatnewnode(4);
    head->left->right = creatnewnode(5);
    preorder(head);
    printf("\n");
    midorder(head);
    printf("\n");
    postorder(head);
    printf("\n");
}