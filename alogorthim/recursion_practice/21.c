#include <stdio.h>
#include <stdlib.h>
typedef struct() // define list1,list2,list
    // list is the integrated list head.
    int main()
{
    return 0;
}
list *integrating(list1 *p, list2 *q)
{ // p replaces list1 head and q replaces list2 head
    if (p == NULL)
    {
        return q;
    }
    // other situation simliar
    // step 2 compare the two list's first data.
    if (p->data > q->data)
    {
        list_head = q;
        list_head->next = integrating(p, q->next);
        return q;
    }
    // the simliar logic..
}
// code given by gemini
Node *integrating(Node *p, Node *q)
{
    // 1. Base Case: 谁空了，就返回另一个
    if (p == NULL)
        return q; // 填空 1: p 没了，返回 q
    if (q == NULL)
        return p; // 填空 2: q 没了，返回 p

    // 2. 决策: 谁小谁做头 (假设我们要从小到大)

    // 情况 A: p 比较小 (或者相等)
    if (p->data <= q->data)
    {
        // 我 (p) 当头。
        // 我的 next 连向 "剩下的 p 和 完整的 q 合并后的结果"
        p->next = integrating(p->next, q); // 填空 3
        return p;
    }

    // 情况 B: q 比较小 (你的代码写的是这种情况)
    else
    {
        // 我 (q) 当头。
        // 我的 next 连向 "完整的 p 和 剩下的 q 合并后的结果"
        q->next = integrating(p, q->next); // 填空 4
        return q;
    }
}