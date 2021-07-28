/**
 * Description : Remove Linked List Elements
 *               Remove all elements from a linked list of integers that have
 *               value val.
 * Author      : Evan Lau
 * Date        : 2016/04/10
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* ptr = head;
    struct ListNode* tmp = NULL;

    if (head == NULL)
    {
        return NULL;
    }

    while (ptr && ptr->val == val)
    {
        head = ptr->next;
        free(ptr);
        ptr = head;
    }
    if (ptr == NULL)
    {
        return NULL;
    }
    ptr = ptr->next;
    tmp = head;

    while (ptr)
    {
        if (ptr->val == val)
        {
            tmp->next = ptr->next;
            free(ptr);
            ptr = tmp->next;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
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

void freeList(struct ListNode* head)
{
    struct ListNode* ptr = head;
    struct ListNode* tmp = head;

    head = NULL;

    if (ptr == NULL)
    {
        return;
    }

    while (ptr)
    {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
    ptr = NULL;
    tmp = NULL;
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
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int arr2[] = {1, 1};
    struct ListNode* head = NULL;

    head = createList(arr, 7);
    printList(head);
    head = removeElements(head, 6);
    printList(head);
    freeList(head);

    head = createList(arr2, 2);
    printList(head);
    head = removeElements(head, 1);
    printList(head);

    return 0;
}
