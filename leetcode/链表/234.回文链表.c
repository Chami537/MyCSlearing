#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct ListNode
{
    int data;
    struct ListNode *next;
};
// 解法1
bool isPalindrome(struct ListNode *head)
{
    int k[100000];
    int index = 0;
    while (head != NULL)
    {
        k[index++] = head->val;
        head = head->next;
    }
    for (int i = 0, j = index - 1; i <= j; i++, j--)
    {
        if (k[i] != k[j])
        {
            return false;
        }
    }
    return true;
}
// 解法2 反转迭代 一个思路
