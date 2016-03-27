/**
 * Description : Range Sum Query - Immutable
 *               Given an integer array nums, find the sum of the elements
 *               between indices i and j (i <= j), inclusive.
 * Author      : Evan lau
 * Date        : 2016/03/27
 */

#include <stdio.h>
#include <stdlib.h>

struct NumArray {
    int * nums;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize)
{
    struct NumArray* numArr = malloc(sizeof(struct NumArray));
    numArr->nums = malloc(numsSize * sizeof(int));
    if (numsSize <= 0) return numArr;
    numArr->nums[0] = nums[0];
    int i;
    for (i = 1 ; i < numsSize ; i++)
    {
        numArr->nums[i] = numArr->nums[i-1] + nums[i];
    }
    return numArr;
}

int sumRange(struct NumArray* numArray, int i, int j)
{
    if (i <= 0) return numArray->nums[j];
    else return numArray->nums[j] - numArray->nums[i-1];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray)
{
    free(numArray->nums);
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    struct NumArray* numArray = NumArrayCreate(arr, 10);

    printf("sum of 0 to 1: %d\n", sumRange(numArray, 0, 1));
    printf("sum of 1 to 2: %d\n", sumRange(numArray, 1, 2));
    printf("sum of 1 to 5: %d\n", sumRange(numArray, 1, 5));
    printf("sum of 8 to 9: %d\n", sumRange(numArray, 8, 9));
    NumArrayFree(numArray);

    return 0;
}
