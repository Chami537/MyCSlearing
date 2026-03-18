struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1==NULL){
        return list2;
    }
    if (list2==NULL){
        return list1;
    }
    struct ListNode dummy;
    struct ListNode* newhead=&dummy;
    struct ListNode* temp=newhead;
    while (list1!=NULL&&list2!=NULL){
        if (list1->val<=list2->val){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }
    }
    if(list1==NULL){
        temp->next=list2;
    }
    if (list2==NULL){
        temp->next=list1;
    }
    return dummy.next;
}
//解法二 
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2){
    if (list1==NULL){
        return list2;
    }
    if (list2==NULL){
        return list1;
    }
    if (list1->val<=list2->val){
        list1->next=mergeTwoLists(list1->next,list2);
        return list1;
    }
    else{
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
    }

}
