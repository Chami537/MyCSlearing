bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    while (fast != NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
//快慢指针
//先跑在判断，只判断快指针，本身判断两次最多访问到null，不会出现null->next这种莫名其妙的东西