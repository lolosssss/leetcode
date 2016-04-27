/**
 * Description : Delete Node in a Linked List
 *               Write a function to delete a node(except the tail) in a singly
 *               linked list, given only access to that node.
 * Author      : Evan Lau
 * Date        : 2016/04/10
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node)
{
    struct ListNode* tmp = node->next;

    node->val = tmp->val;
    node->next = tmp->next;
    free(tmp);
    tmp = NULL;
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
    int arr[5] = {1, 2, 3, 4, 5};
    struct ListNode* head = NULL;
    struct ListNode* node = NULL;

    head = createList(arr, 5);
    printList(head);
    node = head;
    for (int i = 0; i < 2; i++)
    {
        node = node->next;
    }
    deleteNode(node);
    printList(head);

    return 0;
}
