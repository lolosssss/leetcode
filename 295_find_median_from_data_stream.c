/**
 * Description : Find Median from Data Stream
 *               Design a data structure that supports the following two opera-
 *               tions:
 *               . void addNum(int num) - Add a integer number from the data
 *                 stream to the data structure.
 *               . double findMedian() - Return the median of all elements so
 *                 far.
 * Author      : Evan Lau
 * Date        : 2016/05/11
 */

#include <stdio.h>
#include <stdlib.h>

struct MedianFinder {
    int *arr;
    int size;
};

/** Initialize your data structure here. */
struct MedianFinder* MedianFinderCreate()
{
    struct MedianFinder *mf = (struct MedianFinder *)malloc(\
        sizeof(struct MedianFinder));
    mf->arr = (int *)malloc(sizeof(int) * 50000);
    mf->size = 0;

    return mf;
}

/** Inserts a num into the data structure. */
void addNum(struct MedianFinder* mf, int num)
{
    mf->size += 1;
    if (num > mf->arr[mf->size-2])
    {
        mf->arr[mf->size-1] = num;
        return;
    }

    int i = mf->size - 2;

    while (i > -1 && mf->arr[i] > num)
    {
        mf->arr[i+1] = mf->arr[i];
        i--;
    }
    mf->arr[i+1] = num;
}

/** Find the median of current data stream. */
double findMedian(struct MedianFinder* mf)
{
    if (mf->size % 2)
        return mf->arr[mf->size/2];
    return (mf->arr[mf->size/2-1] + mf->arr[mf->size/2]) / 2.0;
}

/** Deallocates memory previously allocated for the data structure .*/
void MedianFinderFree(struct MedianFinder* mf)
{
    free(mf->arr);
    free(mf);
    mf = NULL;
}

int main(void)
{
    struct MedianFinder* mf = MedianFinderCreate();
    addNum(mf, 1);
    addNum(mf, 2);
    printf("%f\n", findMedian(mf));
    addNum(mf, 3);
    printf("%f\n", findMedian(mf));
    MedianFinderFree(mf);

    return 0;
}
