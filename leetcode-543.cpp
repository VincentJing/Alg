#include <iostream>

using namespace std;

// 给你一棵二叉树的根节点，返回该树的 直径 。
// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
// 两节点之间路径的 长度 由它们之间边数表示。

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        depth(root, res);
        return res;
    }

    int depth(TreeNode *root, int &res)
    {
        if (root == nullptr)
            return 0;

        int left_depth = depth(root->left, res);
        int right_depth = depth(root->right, res);

        res = max(res, left_depth + right_depth);
        int depth = max(left_depth, right_depth) + 1;

        return depth;
    }
};