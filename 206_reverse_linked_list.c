/**
 * Description : Reverse Linked List
 *               Reverse a singly linked list.
 * Author      : Evan Lau
 * Date        : 2016/03/27
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *prev = NULL;
    struct ListNode *cur = NULL;
    struct ListNode *next = NULL;

    if (head == NULL)
    {
        return head;
    }

    if (head->next == NULL)
    {
        return head;
    }

    prev = NULL;
    cur = head;
    next = head->next;

    while (next != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;

    return cur;
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
    struct ListNode *head = NULL;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 1; i < 11; i++)
    {
        head = createList(arr, i);
        printList(head);
        head = reverseList(head);
        printList(head);
        freeList(head);
        printf("\n");
    }

    return 0;
}
