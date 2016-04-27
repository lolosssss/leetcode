/**
 * Description : Odd Even Linked List
 *               Given a singly linked list, group all odd nodes together
 *               followed by the even nodes.
 * Author      : Evan Lau
 * Date        : 2016/03/31
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head)
{
    struct ListNode *ptr = head;
    struct ListNode *tmp = NULL;
    struct ListNode *even = NULL;
    struct ListNode *odd = NULL;
    int i = 1;

    if (head == NULL)
    {
        return NULL;
    }

    even = head->next;
    odd = head;
    tmp = ptr->next;
    ptr = ptr->next;

    while (ptr != NULL)
    {
        if (i % 2 == 0)
        {
            odd = ptr;
            even->next = ptr->next;
        }
        else
        {
            even = ptr;
            odd->next = ptr->next;
        }

        i++;
        ptr = ptr->next;
    }

    odd->next = tmp;

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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct ListNode *head = createList(arr, 3);

    printList(head);
    oddEvenList(head);
    printList(head);
    freeList(head);

    return 0;
}
