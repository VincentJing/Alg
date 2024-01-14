#include <iostream>

using namespace std;

// 给你一个整数数组 nums ，其中元素已经按 升序 排列，
// 请你将其转换为一棵 高度平衡 二叉搜索树。
// 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int len = nums.size();

        if (len == 0)
            return nullptr;

        return sortedArrayToBST(nums, 0, len - 1);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        if (end < start)
            return nullptr;

        TreeNode *res = new TreeNode();

        int mid = (start + end) / 2;

        res->val = nums[mid];

        res->left = sortedArrayToBST(nums, start, mid - 1);
        res->right = sortedArrayToBST(nums, mid + 1, end);

        return res;
    }
};

// 辅助函数，用于打印二叉树（前序遍历）
void preOrder(TreeNode *node)
{
    if (node)
    {
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// 清理二叉树占用的内存
void deleteTree(TreeNode *node)
{
    if (node)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    cout << "PreOrder Traversal of constructed BST: ";
    preOrder(root);
    cout << endl;
    deleteTree(root);
    return 0;
}
