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

struct ListNode* merge(struct ListNode* lists[], int beg, int end)
{
    if (beg > end)
        return NULL;
    if (beg == end)
        return lists[beg];

    int mid = (beg + end) / 2;
    struct ListNode *left = merge(lists, beg, mid);
    struct Listnode *right = merge(lists, mid, end);

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
    return merge(lists, 0, k - 1);
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
    int arr1[5] = {5, 4, 3, 2, 1};
    int arr2[6] = {12, 8, 3, 7, 0, 9};
    int arr3[3] = {0, 0, 0};
    int arr4[6] = {5, 2, 5, 0, 1, 10};
    int arr5[4] = {-3, -3, -3, -1};

    struct ListNode *lists[4];
    struct ListNode *list[1];
    struct ListNode *res = NULL;

    lists[0] = createList(arr1, 5);
    lists[1] = createList(arr2, 6);
    lists[2] = createList(arr3, 3);
    lists[3] = createList(arr4, 6);

    list[0] = createList(arr5, 4);

    lists[0] = sortList(lists[0]);
    lists[1] = sortList(lists[1]);
    lists[2] = sortList(lists[2]);
    lists[3] = sortList(lists[3]);

    res = mergeKLists(list, 1);
    printList(res);

    return 0;
}
