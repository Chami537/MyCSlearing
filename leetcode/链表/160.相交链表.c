struct ListNode{
    int data;
    struct ListNode* next;
};
int findlength(struct ListNode *head)
{
    struct ListNode *temp = head;
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;//初始化应该为0
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    //temp是空指针不用free
    return count;
}

struct ListNode *getIntersectionNode(struct ListNode *headA,struct ListNode *headB)
{
    struct ListNode *tempa = headA;
    struct ListNode *tempb = headB;
    int lena=findlength(headA);
    int lenb=findlength(headB);
    int subtract = (lena > lenb) ? (lena - lenb) : (lenb - lena);
    if (lena>lenb){
        for (int i=0;i<subtract;i++){
            tempa=tempa->next;
        }
    }
    else{
        for (int j=0;j<subtract;j++){
            tempb=tempb->next;
        }
    }
    while(tempa!=tempb){
        tempa=tempa->next;
        tempb=tempb->next;
    }
    return tempa;
}
//解法二双指针法,天才来的吧
struct ListNode *getIntersectionNode(struct ListNode *headA,struct ListNode *headB){
    if (headA==NULL||headB==NULL){
        return NULL;
    }
    struct ListNode* pa=headA;
    struct ListNode* pb=headB;
    while(pa!=pb){
        pa=(pa==NULL)?headB:pa->next;
        pb=(pb==NULL)?headA:pb->next;
    }
    return pa;
}