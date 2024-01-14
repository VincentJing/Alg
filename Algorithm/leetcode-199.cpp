#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 给定一个二叉树的 根节点 root，想象自己站在它的右侧
// 按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

//  Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;

        if (root == nullptr)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);

                if (tmp->right)
                    q.push(tmp->right);

                if (i == size - 1)
                {
                    res.push_back(tmp->val);
                }
            }
        }

        return res;
    }
};
