/**
 * Description : Substring with concatenation of All Words
 *               You are given a string, s, and a list of words, words, that are
 *               all of the same length. Find all starting indices of substring
 *               int s that is a concatenation of each word in words exactly
 *               once and without any intervening characters.
 *               For example, given:
 *               s: "barfoothefoobarman"
 *               words: ["foo", "bar"]
 *               You should return the indices: [0,9]. (order does not matter).
 * Author      : Evan Lau
 * Date        : 2016/03/12
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
    int index = 0;
    int i, j;
    int target = 0;
    int wlen = strlen(words[0]);
    int slen = strlen(s);
    int *ret = (int *)malloc(sizeof(int) * 10000);
    int arr[slen - wlen * wordsSize + 1];

    *returnSize = 0;
    for (i = 0; i < wordsSize; i++)
    {
        target += (words[i][0] - 95) * 26;
        for (j = 1; j < wlen; j++)
        {
            target += (words[i][j] - 95) * \
                    (words[i][j - 1] * words[i][j - 1] - 70);
        }
    }

    for (i = 0; i < slen - wlen * wordsSize + 1; i++)
    {
        arr[i] = 0;
    }

    while (*(s + index + wlen * wordsSize - 1) != '\0')
    {
        for (i = 0; i < wordsSize; i++)
        {
            arr[index] += (*(s + index + i * wlen) - 95) * 26;
            for (j = 1; j < wlen; j++)
            {
                arr[index] += (*(s + index + i * wlen + j) - 95) * \
                        (*(s + index + i * wlen + j - 1) * \
                         (*(s + index + i * wlen + j - 1)) - 70);
            }
        }
        index++;
    }

    for (i = 0; i < slen - wlen * wordsSize + 1; i++)
    {
        if (arr[i] == target)
        {
            ret[(*returnSize)++] = i;
        }
    }

    return ret;
}

int main(void)
{
    char *s = "barfoothefoobarman";
    char *words[2] = {"foo", "bar"};
    char *s2 = "barfoofoobarthefoobarman";
    char *words2[3] = {"bar", "foo", "the"};
    char *s3 = "wordgoodgoodgoodbestword";
    char *words3[4] = {"word", "good", "best", "good"};
    char *s4 = "abaababbaba";
    char *words4[4] = {"ab", "ba", "ab", "ba"};
    char *s5 = "cbbabcbac";
    char *words5[2] = {"ab", "cb"};

    int* res = NULL;
    int size = 0;

    res = findSubstring(s, words, 2, &size);
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("]\n");
    free(res);

    res = findSubstring(s2, words2, 3, &size);
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("]\n");
    free(res);

    res = findSubstring(s3, words3, 4, &size);
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("]\n");
    free(res);

    res = findSubstring(s4, words4, 4, &size);
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("]\n");
    free(res);

    res = findSubstring(s5, words5, 2, &size);
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("]\n");
    free(res);

    return 0;
}
