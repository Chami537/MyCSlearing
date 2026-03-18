struct ListNode
{
    int data;
    struct ListNode *next;
};
// 解法一 迭代法
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *temp = head;
    struct ListNode *prev = NULL;
    struct ListNode *after;

    if (temp == NULL)
    {
        return NULL;
    }

    while (temp != NULL)
    {
        after = temp->next; // 先保存下一个
        temp->next = prev;  // ★ 立刻反转指针
        prev = temp;        // prev 前进
        temp = after;       // temp 前进
    }

    return prev;
}
// 方法二 递归法
struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode *newhead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
