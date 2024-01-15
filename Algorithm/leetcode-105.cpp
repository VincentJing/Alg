#include <iostream>

using namespace std;

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *build(
        vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd,
        int inStart, int inEnd)
    {
        if (preStart > preEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int rootVal = root->val;
        int inRoot = inStart;

        while (inRoot < inEnd)
        {
            if (rootVal == inorder[inRoot])
                break;
            inRoot++;
        }

        int leftSize = inRoot - inStart;
        int rightSize = inEnd - inRoot;

        if (leftSize)
        {
            root->left = build(
                preorder, inorder, preStart + 1, preStart + leftSize, inStart,
                inRoot - 1);
        }

        if (rightSize)
        {
            root->right = build(
                preorder, inorder, preStart + 1 + leftSize,
                preStart + leftSize + rightSize, inRoot + 1, inRoot + rightSize);
        }

        return root;
    }
};
