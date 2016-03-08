/**
 * Description : Given an array of integers, find two numbers such that they 
                 add up to a specific target number.
                 The function twoSum should return indices of the two numbers
                 such that they add up to the target, where index1 must be less
                 than index2. Please note that your returned answers are not 
                 zero-based.
                 You may assum that each input would have exactly one solution.
 * Example     : Input: numbers = {2, 7, 11, 15}, target = 9
                 Output: index1 = 1, index2 = 2.
 * Author      : Evan Lau
 * Date        : 2015.10.12
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *twoSum2(int *nums, int numSize, int target)
{
    if ((NULL == nums) | (numSize < 2))
    {
        return NULL;
    }

    int *ret = (int *)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numSize - 1; i++)
    {
        for (int j = i + 1; j < numSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                *ret = i + 1;
                *(ret + 1) = j + 1;
                return ret;
            }
        }
    }
    return NULL;
}


//////////////////////////////////////////////////////

#define PRIME 271

typedef struct linkedListNode* plistNode;
typedef struct linkedListNode
{
    int index;
    plistNode next;
}listNode;

void hashTableFree(plistNode hashTable, int primeNumber)
{
    int index = 0;
    plistNode tmp;

    for (int index = 0; index < primeNumber; index++)
    {
        plistNode tail = hashTable[index].next;
        while (NULL != tail)
        {
            tmp = tail;
            tail = tail->next;
            free(tmp);
        }
    }
    free(hashTable);
}

int *twoSum(int *nums, int numSize, int target)
{
    if ((nums == NULL) | (numSize < 2))
        return NULL;

    int index = 0;

    // create a hash table
    int primeNumber = PRIME;
    plistNode hashTable = (plistNode)malloc(sizeof(listNode) * primeNumber);
    if (NULL == hashTable)
    {
        printf("memory allocation for hashTable failed!\n");
        return NULL;
    }

    // initialise the hash table
    for (index = 0; index < primeNumber; index++)
    {
        hashTable[index].index = -1;
        hashTable[index].next = NULL;
    }

    // assign numbers to the hash table
    for (index = 0; index < numSize; index++)
    {
        int bias = abs(nums[index] % primeNumber);
        if (-1 == hashTable[bias].index)
        {
            hashTable[bias].index = index;
        }
        else
        {
            plistNode tail = NULL;
            tail = (plistNode)malloc(sizeof(listNode));
            if (NULL == tail)
            {
                printf("memory allocation for tail failed!\n");
                return NULL;
            }

            tail->index = index;
            tail->next = hashTable[bias].next;
            hashTable[bias].next = tail;
        }
    }

    // searching
    int* ret = (int *)malloc(sizeof(int) * 2);
    for (index = 0; index < numSize; index++)
    {
        int bias = abs((target - nums[index]) % primeNumber);
        if (-1 == hashTable[bias].index)
        {
            continue;
        }
        if ((nums[hashTable[bias].index] == (target - nums[index])) & (hashTable[bias].index != index))
        {
            ret[0] = index + 1;
            ret[1] = hashTable[bias].index + 1;
            hashTableFree(hashTable, primeNumber);
            return ret;
        }
        else
        {
            plistNode tail = hashTable[bias].next;
            while (NULL != tail)
            {
                if (nums[tail->index] == (target -  nums[index]))
                {
                    ret[0] = index + 1;
                    ret[1] = tail->index + 1;
                    hashTableFree(hashTable, primeNumber);
                    return ret;
                }
                else
                {
                    tail = tail->next;
                }
            }
        }
    }
    hashTableFree(hashTable, primeNumber);
    return NULL;
}

int main()
{
    int num[100];
    int target = 155;
    int *res;
    clock_t start;
    clock_t end;

    for (int i = 0; i < 100; i++)
    {
        num[i] = i + 1;
    }
    
    start = clock();
    res = twoSum2(num, sizeof(num), target);
    end = clock();
    
    printf("%d, %d\n", *res, *(res + 1));
    printf("time:%ld\n", end - start);

    free(res);
    res = NULL;
    
    return 0;
}



