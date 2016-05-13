/**
 * Description : Binary Tree Preorder Traversal
 *               Given a binary tree, return the preorder traversal of its
 *               nodes' values.
 * Author      : Evan Lau
 * Date        : 2016/05/13
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* preorderTraversal(struct TreeNode *root, int *returnSize)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }

    int left = 0;
    int right = 0;
    int *leftRet = NULL;
    int *rightRet = NULL;

    if (root->left)
    {
        leftRet = preorderTraversal(root->left, &left);
    }
    if (root->right)
    {
        rightRet = preorderTraversal(root->right, &right);
    }

    int len = left + right + 1;
    *returnSize = len;

    int *ret = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            *(ret + i) = root->val;
        }
        else if (i > 0 && i <= left)
        {
            *(ret + i) = *(leftRet + i - 1);
        }
        else if (i > left)
        {
            *(ret + i) = *(rightRet + i - left - 1);
        }
    }

    free(leftRet);
    free(rightRet);

    return ret;
}
