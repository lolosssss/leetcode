/**
 * Description : Reverse Nodes in k-Group
 *               Given a linked list, reverse the nodes of a linked list k at a
 *               time and return its modified list.
 *               If the number of nodes is not a multiple of k then left-out
 *               nodes in the end should remain as it is.
 * Author      : Evan Lau
 * Date        : 2016/03/09
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* begin, struct ListNode* end)
{
    struct ListNode root;
    struct ListNode *prev = NULL;
    struct ListNode *ret = NULL;
    struct ListNode *tmp = NULL;

    ret = begin;
    root.next = NULL;
    prev = &root;

    while (begin)
    {
        tmp = begin->next;
        begin->next = prev->next;
        prev->next = begin;
        begin = tmp;
    }

    end->next = root.next;

    return ret;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode root;
    struct ListNode *cur = head;
    struct ListNode *tail = NULL;
    struct ListNode *tmp = NULL;
    int i = 0;
    int cnt = 0;

    if (!k)
        return head;

    root.next = head;
    tail = &root;

    while (cur)
    {
        cnt++;
        if (cnt %k == 0)
        {
            tmp = cur->next;
            cur->next = NULL;
            tail = reverseList(tail->next, tail);
            tail->next = tmp;
            cur = tmp;
            continue;
        }

        cur = cur->next;
    }

    return root.next;
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
    int arr[20];
    struct ListNode *l[18];

    for (int i = 0; i < 20; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 18; i++)
    {
        l[i] = createList(arr, 20);
    }

    for (int i = 0; i < 18; i++)
    {
        l[i] = reverseKGroup(l[i], i + 2);
    }

    for (int i = 0; i < 18; i++)
    {
        printf("No. %d testcase:\n", i + 1);
        printList(l[i]);
    }

    return 0;
}
