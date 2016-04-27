/**
 * Description : Merge Intervals
 *               Given a collection of intervals,merge all overlapping intervals
 * Author      : Evan Lau
 * Date        : 2016/04/20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Interval {
    int start;
    int end;
};

struct Interval* merge(struct Interval* intervals, int intervalsSize,
                       int *returnSize)
{
    int i = 0;
    int start = 0;
    int tmp = 0;
    int min = 9999;
    int max = 0;
    int arr[10000];

    struct Interval* ret = (struct Interval*)malloc(sizeof(struct Interval) * intervalsSize);

    memset(arr, 0, sizeof(arr));

    *returnSize = 0;
    for (i = 0; i < intervalsSize; i++)
    {
        tmp = intervals[i].end - intervals[i].start;
        if (arr[intervals[i].start] == 0)
        {
            if (tmp == 0)
                arr[intervals[i].start] = -1;
            else
                arr[intervals[i].start] = tmp;
        }
        else
        {
            if (tmp != 0 && tmp > arr[intervals[i].start])
            {
                arr[intervals[i].start] = tmp;
            }
        }

        if (intervals[i].start < min)
            min = intervals[i].start;
        if (intervals[i].end > max)
            max = intervals[i].end;
    }

    i = min;
    while (i <= max)
    {
        if (start == 0)
        {
            if (arr[i] == 0)
            {
                i++;
                continue;
            }
            else if (arr[i] == -1)
            {
                ret[*returnSize].start = i;
                ret[(*returnSize)++].end = i;
            }
            else
            {
                tmp = arr[i];
                ret[*returnSize].start = i;
                start = 1;
            }
        }
        else
        {
            if (arr[i] > 0)
            {
                if (arr[i] > tmp - 1)
                    tmp = arr[i];
                else
                    tmp--;
            }
            else
            {
                tmp--;
                if (tmp == 0)
                {
                    ret[(*returnSize)++].end = i;
                    start = 0;
                }
            }
        }
        i++;
    }

    return ret;
}

int main(void)
{
    struct Interval intervals1[4];
    struct Interval intervals2[2];
    struct Interval* ret;
    int size = 0;

    intervals1[0].start = 1;
    intervals1[0].end = 3;
    intervals1[1].start = 2;
    intervals1[1].end = 6;
    intervals1[2].start = 8;
    intervals1[2].end = 10;
    intervals1[3].start = 15;
    intervals1[3].end = 18;

    intervals2[0].start = 1;
    intervals2[0].end = 4;
    intervals2[1].start = 2;
    intervals2[1].end = 5;

    ret = merge(intervals1, 4, &size);
    for (int i = 0; i < size; i++)
    {
        printf("[%d, %d] ", ret[i].start, ret[i].end);
    }
    printf("\n");
    free(ret);

    ret = merge(intervals2, 2, &size);
    for (int i = 0; i < size; i++)
    {
        printf("[%d, %d] ", ret[i].start, ret[i].end);
    }
    printf("\n");
    free(ret);

    return 0;
}
