/**
 * Description : Maximum Depth of Binary Tree
 *               Given a binary tree, find its maximum depth.
 * Author      : Evan Lau
 * Date        : 2016/05/27
 */

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (!root)
        return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return l > r ? ++l : ++r;
}
