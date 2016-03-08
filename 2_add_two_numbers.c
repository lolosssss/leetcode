/**
 * Description : Add Two Numbers
                 You are given two linked lists representing two non-negative 
                 numbers. The digits are stored in reverse order and each and
                 each of their nodes contain a single digit. Add the two numbers
                 and return it as a linked list.
 * Example     : Input:(2 -> 4 -> 3) + (5 -> 6 -> 4)
                 Output: 7 -> 0 -> 8
 * Author      : Evan Lau
 * Date        : 2015.10.14
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *ret = NULL;
    struct ListNode *new = NULL;
    struct ListNode *tmp = NULL;

    int carry = 0;
    int tmp_sum = 0;
    int val1;
    int val2;

    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->next = NULL;
    ret = new;
    tmp = new;
    tmp_sum = l1->val + l2->val;
    new->val = (tmp_sum > 9) ? (tmp_sum - 10) : tmp_sum;
    carry = tmp_sum / 10;

    while (l1->next != NULL || l2->next != NULL)
    {
        if (l1->next != NULL)
        {
            l1 = l1->next;
            val1 = l1->val;
        }
        else
        {
            val1 = 0;
        }
        if (l2->next != NULL)
        {
            l2 = l2->next;
            val2 = l2->val;
        }
        else
        {
            val2 = 0;
        }

        new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->next = NULL;
        tmp->next = new;
        tmp = new;
        tmp_sum = val1 + val2 + carry;
        new->val = (tmp_sum > 9) ? (tmp_sum - 10) : tmp_sum;
        carry = tmp_sum / 10;
    }

    if (carry > 0)
    {
        new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->next = NULL;
        tmp->next = new;
        tmp = new;
        new->val = carry;
    }

    return ret;
}

struct ListNode* createList(int *arr, int len)
{
    struct ListNode *ret = NULL;
    struct ListNode *tmp = NULL;
    
    ret = (struct ListNode*)malloc(sizeof(struct ListNode) * len);

    for (int i = 0; i < len - 1; i++)
    {
        (ret + i)->next = ret + i + 1;
    }
    (ret + len - 1)->next = NULL;

    for (int index = 0; index < len; index++)
    {
        ret[index].val = arr[index];
    }

    return ret;
}

void printResult(struct ListNode *result)
{
    struct ListNode *tmp = result;

    while (tmp != NULL)
    {
        printf("%d\n", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *result = NULL;

    int arr1[] = {9, 9};
    int arr2[] = {1};

    l1 = createList(arr1, 2);
    l2 = createList(arr2, 1);
    printResult(l1);
    printResult(l2);

    result = addTwoNumbers(l1, l2);

    printResult(result);
    
    return 0;
}



