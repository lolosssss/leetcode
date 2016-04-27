/**
 * Description : Insert Interval
 *               Given a set of non-overlapping intervals, insert a new interval
 *               into the intervals (merge if necessary).
 * Author      : Evan Lau
 * Date        : 2016/04/19
 */

#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

struct Interval* insert(struct Interval* intervals, int intervalsSize,
                        struct Interval newInterval, int* returnSize)
{
    int left = 0;
    int right = intervalsSize - 1;
    int i;
    struct Interval* ret = NULL;

    if (intervalsSize == 0)
    {
        *returnSize = 1;
        ret = (struct Interval *)malloc(sizeof(struct Interval));
        ret[0].start = newInterval.start;
        ret[0].end = newInterval.end;

        return ret;
    }

    *returnSize = 0;
    while (left < intervalsSize && intervals[left].end < newInterval.start)
    {
        left++;
        (*returnSize)++;
    }
    while (right >= 0 && intervals[right].start > newInterval.end)
    {
        right--;
        (*returnSize)++;
    }
    (*returnSize)++;

    ret = (struct Interval *)malloc(sizeof(struct Interval) * *returnSize);
    for (i = 0; i < left; i++)
    {
        ret[i].start = intervals[i].start;
        ret[i].end = intervals[i].end;
    }

    if (left < right)
    {
        if (intervals[left].start <= newInterval.start)
        {
            ret[left].start = intervals[left].start;
        }
        else
        {
            ret[left].start = newInterval.start;
        }

        if (intervals[right].end >= newInterval.end)
        {
            ret[left].end = intervals[right].end;
        }
        else
        {
            ret[left].end = newInterval.end;
        }
    }
    else if (left == right)
    {
        if (intervals[left].start <= newInterval.start &&
            intervals[left].end > newInterval.end)
        {
            ret[left].start = intervals[left].start;
            ret[left].end = intervals[left].end;
        }
        else if (intervals[left].start <= newInterval.start &&
                 intervals[left].end <= newInterval.end)
        {
            ret[left].start = intervals[left].start;
            ret[left].end = newInterval.end;
        }
        else if (intervals[left].start > newInterval.start &&
                 intervals[left].end > newInterval.end)
        {
            ret[left].start = newInterval.start;
            ret[left].end = intervals[left].end;
        }
        else
        {
            ret[left].start = newInterval.start;
            ret[left].end = newInterval.end;
        }
    }
    else
    {
        ret[left].start = newInterval.start;
        ret[left].end = newInterval.end;
    }

    left++;
    for (i = right + 1; i < intervalsSize; i++)
    {
        ret[left].start = intervals[i].start;
        ret[left].end = intervals[i].end;
        left++;
    }

    return ret;
}

int main(void)
{
    struct Interval* intervals1 = (struct Interval *)malloc(sizeof(struct Interval) * 2);
    struct Interval* intervals2 = (struct Interval *)malloc(sizeof(struct Interval) * 5);
    struct Interval* intervals3 = NULL;
    struct Interval* intervals4 = (struct Interval *)malloc(sizeof(struct Interval));

    struct Interval new1;
    struct Interval new2;
    struct Interval new3;
    struct Interval new4;

    struct Interval* res = NULL;

    int size = 0;

    intervals1[0].start = 1;
    intervals1[0].end = 3;
    intervals1[1].start = 6;
    intervals1[1].end = 9;

    intervals2[0].start = 1;
    intervals2[0].end = 2;
    intervals2[1].start = 3;
    intervals2[1].end = 5;
    intervals2[2].start = 6;
    intervals2[2].end = 7;
    intervals2[3].start = 8;
    intervals2[3].end = 10;
    intervals2[4].start = 12;
    intervals2[4].end = 16;

    intervals4[0].start = 1;
    intervals4[0].end = 5;

    new1.start = 2;
    new1.end = 5;

    new2.start = 4;
    new2.end = 9;

    new3.start = 5;
    new3.end = 7;

    new4.start = 6;
    new4.end = 8;

    res = insert(intervals1, 2, new1, &size);

    int i;
    for (i = 0; i < size; i++)
    {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }
    printf("\n");
    free(res);

    res = insert(intervals2, 5, new2, &size);
    for (i = 0; i < size; i++)
    {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }
    printf("\n");
    free(res);

    res = insert(intervals3, 0, new3, &size);
    for (i = 0; i < size; i++)
    {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }
    printf("\n");
    free(res);

    res = insert(intervals4, 1, new4, &size);
    for (i = 0; i < size; i++)
    {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }
    printf("\n");
    free(res);

    return 0;
}
