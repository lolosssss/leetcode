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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode* head = NULL;

    head = mergeTwoLists(lists[0], lists[1]);

    for (int i = 2; i < listsSize; i++)
    {
        head = mergeTwoLists(head, lists[i]);
    }

    return head;
}

int main(void)
{
    int arr1[5] = {5, 4, 3, 2, 1};
    int arr2[6] = {12, 8, 3, 7, 0, 9};
    int arr3[3] = {0, 0, 0};
    int arr4[6] = {5, 2, 5, 0, 1, 10};

    struct ListNode *lists[4];
    struct ListNode *res = NULL;

    lists[0] = createList(arr1, 5);
    lists[1] = createList(arr2, 6);
    lists[2] = createList(arr3, 3);
    lists[3] = createList(arr4, 6);

    lists[0] = sortList(lists[0]);
    lists[1] = sortList(lists[1]);
    lists[2] = sortList(lists[2]);
    lists[3] = sortList(lists[3]);

    res = mergeKLists(lists, 4);
    printList(res);

    return 0;
}
