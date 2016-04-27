/**
 * Description : Swap Nodes in Pairs
 *               Given a linked list, swap every two adjacent nodes and return
 *               its head.
 * Author      : Evan Lau
 * Date        : 2016/03/08
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
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *cur = head;
    struct ListNode *n1 = NULL;
    struct ListNode *n2 = NULL;

    if (!head || !head->next)
        return head;

    n1 = cur->next;
    head = n1;

    if (!n1->next)
    {
        n1->next = cur;
        cur->next = NULL;
        return head;
    }

    n2 = n1->next;
    while (cur && n1 && n2)
    {
        n1->next = cur;
        if (!n2->next)
        {
            cur->next = n2;
            break;
        }
        else
        {
            cur->next = n2->next;
        }
        cur = n2;
        n1 = cur->next;
        n2 = n1->next;
    }

    if (!n2)
    {
        n1->next = cur;
        cur->next = NULL;
    }

    return head;
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
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    struct ListNode *l0 = createList(arr, 0);
    struct ListNode *l1 = createList(arr, 1);
    struct ListNode *l2 = createList(arr, 2);
    struct ListNode *l3 = createList(arr, 3);
    struct ListNode *l4 = createList(arr, 4);
    struct ListNode *l5 = createList(arr, 5);
    struct ListNode *l6 = createList(arr, 6);
    struct ListNode *l7 = createList(arr, 7);
    struct ListNode *l8 = createList(arr, 8);
    struct ListNode *l9 = createList(arr, 9);
    struct ListNode *l10 = createList(arr, 10);
    struct ListNode *l11 = createList(arr, 11);
    struct ListNode *l12 = createList(arr, 12);
    struct ListNode *l13 = createList(arr, 13);
    struct ListNode *l14 = createList(arr, 14);

    l0 = swapPairs(l0);
    l1 = swapPairs(l1);
    l2 = swapPairs(l2);
    l3 = swapPairs(l3);
    l4 = swapPairs(l4);
    l5 = swapPairs(l5);
    l6 = swapPairs(l6);
    l7 = swapPairs(l7);
    l8 = swapPairs(l8);
    l9 = swapPairs(l9);
    l10 = swapPairs(l10);
    l11 = swapPairs(l11);
    l12 = swapPairs(l12);
    l13 = swapPairs(l13);
    l14 = swapPairs(l14);

    printList(l0);
    printList(l1);
    printList(l2);
    printList(l3);
    printList(l4);
    printList(l5);
    printList(l6);
    printList(l7);
    printList(l8);
    printList(l9);
    printList(l10);
    printList(l11);
    printList(l12);
    printList(l13);
    printList(l14);

    freeList(l0);
    freeList(l1);
    freeList(l2);
    freeList(l3);
    freeList(l4);
    freeList(l5);
    freeList(l6);
    freeList(l7);
    freeList(l8);
    freeList(l9);
    freeList(l10);
    freeList(l11);
    freeList(l12);
    freeList(l13);
    freeList(l14);

    return 0;
}
