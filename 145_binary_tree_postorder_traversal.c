/**
 * Description : Binary Tree Postorder Traversal
 *               Given a binary tree, return the postorder traversal of its
 *               nodes' values.
 * Author      : Evan Lau
 * Date        : 2016/05/26
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *postorderTraversal(struct TreeNode *root, int *returnSize)
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
        leftRet = postorderTraversal(root->left, &left);
    }
    if (root->right)
    {
        rightRet = postorderTraversal(root->right, &right);
    }

    int len = left + right + 1;
    *returnSize = len;

    int *ret = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            *(ret + i) = root->val;
        }
        else if (i >= 0 && i < left)
        {
            *(ret + i) = *(leftRet + i);
        }
        else if (i >= left && i < right + left)
        {
            *(ret + i) = *(rightRet + i - left);
        }
    }

    return ret;
}
