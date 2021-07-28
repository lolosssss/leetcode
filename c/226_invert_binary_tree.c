/**
 * Description : Invert Binary Tree
 * Author      : Evan Lau
 * Date        : 2016/05/25
 */

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
    struct TreeNode *ptr = NULL;

    if (root)
    {
        ptr = root->left;
        root->left = root->right;
        root->right = ptr;
        invertTree(root->left);
        invertTree(root->right);
    }

    return root;
}
