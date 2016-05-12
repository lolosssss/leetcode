/**
 * Description : Binary Tree Paths
 *               Given a binary tree, return all root-to-leaf paths.
 * Author      : Evan Lau
 * Date        : 2016/05/12
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    int leftSize = 0;
    int rightSize = 0;
    char **ret = NULL;
    char **leftRet = NULL;
    char **rightRet = NULL;

    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        *returnSize = 1;
        ret = (char **)malloc(sizeof(char *));
        ret[0] = (char *)malloc(sizeof(char) * 16);
        sprintf(ret[0], "%d", root->val);
        return ret;
    }

    if (root->left != NULL)
    {
        leftRet = binaryTreePaths(root->left, &leftSize);
    }
    if (root->right != NULL)
    {
        rightRet = binaryTreePaths(root->right, &rightSize);
    }

    *returnSize = leftSize + rightSize;
    ret = (char **)malloc(sizeof(char *) * *returnSize);
    for (int i = 0; i < leftSize; i++)
    {
        ret[i] = (char *)malloc(sizeof(char) * 256);
        sprintf(ret[i], "%d->", root->val);
        strcat(ret[i], leftRet[i]);
    }
    for (int i = leftSize; i < *returnSize; i++)
    {
        ret[i] = (char *)malloc(sizeof(char) * 256);
        sprintf(ret[i], "%d->", root->val);
        strcat(ret[i], rightRet[i - leftSize]);
    }

    return ret;
}
