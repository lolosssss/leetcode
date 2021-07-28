/**
 * Description : Remove Duplicates from Sorted List
 *               Given a sorted linked list, delete all duplicates such that
 *               each element appear only once.
 * Author      : Evan Lau
 * Date        : 2016/04/09
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *ptr = head;
    struct ListNode *tmp = head;

    if (head == NULL)
    {
        return NULL;
    }

    ptr = ptr->next;

    while (ptr)
    {
        if (tmp->val == ptr->val)
        {
            tmp->next = ptr->next;
            free(ptr);
        }
        else
        {
            tmp = ptr;
        }
        ptr = tmp->next;
    }

    return head;
}

struct ListNode* createList(int* arr, int len)
{
    struct ListNode* ptr = NULL;
    struct ListNode* head = NULL;
    struct ListNode* tmp = NULL;

    if (len == 0)
    {
        return NULL;
    }

    ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->val = arr[0];
    ptr->next = NULL;
    head = ptr;
    tmp = ptr;

    for (int i = 1; i < len; i++)
    {
        ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
        ptr->val = arr[i];
        ptr->next = NULL;
        tmp->next = ptr;
        tmp = ptr;
    }

    return head;
}

void printList(struct ListNode* head)
{
    struct ListNode* ptr = head;

    while (ptr)
    {
        printf("%d -> ", ptr->val);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main(void)
{
    int arr[5] = {1, 1, 2, 3, 3};
    struct ListNode* head = NULL;

    head = createList(arr, 5);
    printList(head);
    deleteDuplicates(head);
    printList(head);

    return 0;
}
