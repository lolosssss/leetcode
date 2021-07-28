/**
 * Description : Linked List Cycle
 *               Given a linked list, determine if it has a cycle in it.
 * Author      : Evan Lau
 * Date        : 2016/05/14
 */

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    struct ListNode *p = head;
    struct ListNode *q = head;

    while (p && p->next)
    {
        p = p->next->next;
        q = q->next;
        if (p == q)
            return true;
    }

    return false;
}

int main(void)
{
    struct ListNode n = {0, &n};
    printf("%d\n", hasCycle(&n));

    struct ListNode n1 = {0, NULL};
    struct ListNode n2 = {0, &n1};
    struct ListNode n3 = {0, &n2};
    n1.next = &n2;
    printf("%d\n", hasCycle(&n3));
    n.next = NULL;
    printf("%d\n", hasCycle(&n));

    return 0;
}
