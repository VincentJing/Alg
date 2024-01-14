#include <iostream>
#include <unordered_map>

using namespace std;

// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，
// 求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
// 路径 不需要从根节点开始，也不需要在叶子节点结束，
// 但是路径方向必须是向下的（只能从父节点到子节点）。

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        // key: 根节点到当前节点路径和 value: 路径条数
        unordered_map<long long, int> map;
        // 路径和为0，且存在一种可能的情况，即直接不选取任何节点
        map[0] = 1;

        return dfs(root, map, 0, targetSum);
    }

    int dfs(
        TreeNode *root, unordered_map<long long, int> &map, long long cur,
        int targetSum)
    {
        if (root == nullptr)
            return 0;

        cur += root->val;

        int res = 0;

        if (map.find(cur - targetSum) != map.end())
        {
            res += map[cur - targetSum];
        }

        map[cur] += 1;

        res += dfs(root->left, map, cur, targetSum);
        res += dfs(root->right, map, cur, targetSum);

        map[cur] -= 1;

        return res;
    }
};
