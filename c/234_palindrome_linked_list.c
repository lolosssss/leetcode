/**
 * Description : Palindrome Linked List
 *               Given a singly linked list, determine if it is a palindrome.
 * Author      : Evan Lau
 * Date        : 2016/04/11
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head)
{
    struct ListNode* ptr = head;
    int a[60000];
    int i = 0;
    int j = 0;

    while (ptr)
    {
        a[i++] = ptr->val;
        ptr = ptr->next;
    }

    while (j < i)
    {
        if (a[j++] != a[--i])
        {
            return false;
        }
    }
    return true;
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
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int arr2[] = {1, 2, 3, 4, 5, 5, 3, 2, 1};
    struct ListNode* head = NULL;

    head = createList(arr, 9);
    printList(head);
    printf("%d\n", isPalindrome(head));
    freeList(head);

    head = createList(arr2, 9);
    printList(head);
    printf("%d\n", isPalindrome(head));
    freeList(head);

    return 0;
}
