/**
 * Description : Rotate List
 *               Given a list, rotate the list to the right by k place, where k
 *               is non-negative.
 * Author      : Evan Lau
 * Date        : 2016/04/24
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    int i = 0;;
    struct ListNode* ptr = head;
    struct ListNode* k_next = head;

    if (head == NULL)
    {
        return head;
    }

    while (k_next && i < k)
    {
        k_next = k_next->next;
        i++;
    }
    if (k_next == NULL)
    {
        k = k % i;
        if (k == 0)
            return head;

        k_next = head;
        i = 0;
        while (k_next && i < k)
        {
            k_next = k_next->next;
            i++;
        }
    }

    while (k_next->next)
    {
        ptr = ptr->next;
        k_next = k_next->next;
    }
    k_next->next = head;
    head = ptr->next;
    ptr->next = NULL;

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
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode *head = createList(arr, 5);

    printList(head);
    head = rotateRight(head, 2);
    printList(head);
    freeList(head);

    return 0;
}
