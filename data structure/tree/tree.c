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
int height(node *root)
{
    if (root == NULL)
        return 0;
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return leftheight > rightheight ? (leftheight + 1) : (rightheight + 1);
}
int countnode(node *root)
{
    if (root == NULL)
        return 0;
    return countnode(root->left) + countnode(root->right) + 1;
}
int issymmetric(node *root)
{
    if (root == NULL)
        return 1;
    return ismirror(root->left, root->right);
}

int ismirror(node *left, node *right)
{
    if (left == NULL && right == NULL)
        return 1;
    if (left == NULL || right == NULL)
        return 0;
    return left->data == right->data && ismirror(left->left, right->right) && ismirror(left->right, right->left);
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