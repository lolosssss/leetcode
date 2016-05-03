/**
 * Description : Same Tree
 *               Given two binary trees, write a functio to check if they are
 *               equal or not.
 * Author      : Evan Lau
 * Date        : 2016/05/03
 */

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p != NULL && q != NULL)
    {
        if (p->val == q->val)
        {
            if (isSameTree(p->left, q->left) == false)
            {
                return false;
            }
            if (isSameTree(p->right, q->right) == false)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if (p == NULL && q == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }

    return true;
}
