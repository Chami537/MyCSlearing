struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            struct ListNode *meet = fast;
            fast = head;
            while (fast != meet)
            {
                meet = meet->next;
                fast = fast->next;
                if (fast == meet)
                {
                    return fast;
                }
            }
            // 如果头节点就是环，并在头节点相遇的话，不会进入while循环，这个时候我们需要在外面补充一个return
            return fast;
            //如果你的 return 语句依赖于循环执行（写在循环体里面），一定要检查“如果循环一次都不执行”会发生什么。
        }
    }

    return NULL;
}
