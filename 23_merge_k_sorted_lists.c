/**
 * Description : Merge k Sorted Lists
 *               Merge k sorted lists and return it as one sorted list. Analyze
 *               and describeits complesity.
 * Author      : Evan Lau
 * Date        : 2016/03/04
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;

    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            cur->next = l2;
            l2 = l2->next;
        }
        else
        {
            cur->next = l1;
            l1 = l1->next;
        }
        cur = cur->next;
    }

    if (l1)
    {
        cur->next = l1;
    }
    else
    {
        cur->next = l2;
    }

    return head->next;
}

struct ListNode* merge(struct ListNode** lists, int beg, int end)
{
    if (beg > end)
        return NULL;
    if (beg == end)
        return lists[beg];

    int mid = (beg + end) / 2;
    struct ListNode *left = merge(lists, beg, mid);
    struct ListNode *right = merge(lists, mid + 1, end);

    return mergeTwoLists(left, right);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    return merge(lists, 0, listsSize - 1);
}

struct ListNode* createList(int *nums, int numsSize)
{
    int cnt = 0;
    struct ListNode *head = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *cur = NULL;

    if (numsSize == 0)
        return NULL;

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

    if (head == NULL)
        return NULL;

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
    int arr1[0] = {};
    int arr2[0] = {};

    struct ListNode *lists[2];
    struct ListNode *res = NULL;

    lists[0] = createList(arr1, 0);
    lists[1] = createList(arr2, 0);

    lists[0] = sortList(lists[0]);
    lists[1] = sortList(lists[1]);

    res = mergeKLists(lists, 2);
    printList(res);

    return 0;
}
