/**
 * Description : Merge Two Sorted Lists
 *               Merge two sorted linked lists and return it as a new list. The
 *               new list should be made by splicing together the nodes of the
 *               two lists.
 * Author      : Evan Lau
 * Date        : 2016/03/03
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *ptr = head;
    struct ListNode *tmp = head;

    if (l1 == NULL && l2 != NULL)
    {
        return l2;
    }
    if (l1 != NULL && l2 == NULL)
    {
        return l1;
    }
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }

    if (p->val <= q->val)
    {
        ptr->val = p->val;
        p = p->next;
    }
    else
    {
        ptr->val = q->val;
        q = q->next;
    }

    while (p != NULL && q != NULL)
    {
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        ptr->next = tmp;
        ptr = ptr->next;
        if (p->val <= q->val)
        {
            ptr->val = p->val;
            p = p->next;
        }
        else
        {
            ptr->val = q->val;
            q = q->next;
        }
    }

    if (p == NULL)
    {
        while (q != NULL)
        {
            tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
            ptr->next = tmp;
            ptr = ptr->next;
            ptr->val = q->val;
            q = q->next;
        }
    }

    if (q == NULL)
    {
        while (p != NULL)
        {
            tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
            ptr->next = tmp;
            ptr = ptr->next;
            ptr->val = p->val;
            p = p->next;
        }
    }

    ptr->next = NULL;

    return head;
}

struct ListNode* createList(int *nums, int numsSize)
{
    int cnt = 0;
    struct ListNode *head = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *cur = NULL;

    cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur->val = nums[cnt++];
    head = cur;
    tmp =cur;
    numsSize--;

    while (numsSize--)
    {
        cur = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur->val = nums[cnt++];
        tmp->next = cur;
        tmp = cur;
    }
    tmp->next = NULL;

    return head;
}

struct ListNode* sortList(struct ListNode *head)
{
    int tmp;
    struct ListNode *p = NULL;
    struct ListNode *q = NULL;

    for (p = head; p->next != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->val > q->val)
            {
                tmp = p->val;
                p->val = q->val;
                q->val = tmp;
            }
        }
    }

    return head;
}

void printList(struct ListNode *head)
{
    struct ListNode *tmp = head;

    while (tmp != NULL)
    {
        printf("%d->", tmp->val);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void freeList(struct ListNode *head)
{
    struct ListNode *p = head;
    struct ListNode *tmp = NULL;

    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }

    head = NULL;
}

int main(void)
{
    int arr1[1] = {2};
    int arr2[1] = {1};
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *res = NULL;

    l1 = createList(arr1, 1);
    l2 = createList(arr2, 1);

    l1 = sortList(l1);
    l2 = sortList(l2);
    res = mergeTwoLists(l1, l2);
    printList(res);

    freeList(l1);
    freeList(l2);
    freeList(res);

    return 0;
}
