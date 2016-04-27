/**
 * Description : Remove Nth Node From End of List
 *               Given a linked list, remove the nth node from the end of list
 *               and return its head.
 * Note        : 1) Given n will always be valid.
 *               2) Try to do this in one pass.
 * Author      : Evan Lau
 * Date        : 2016/03/02
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *left = head;
    struct ListNode *right = head;
    struct ListNode *tmp = NULL;

    for (int i = 0; i < n; i++)
    {
        right = right->next;
    }

    if (right == NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
        tmp = NULL;

        return head;
    }

    while (right->next != NULL)
    {
        right = right->next;
        left = left->next;
    }

    tmp = left->next;
    left->next = tmp->next;
    free(tmp);
    tmp = NULL;

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

int main(void)
{
    struct ListNode *head = NULL;

    int arr[1] = {1};

    head = createList(arr, 1);

    printList(head);
    head = removeNthFromEnd(head, 1);
    printList(head);

    return 0;
}
