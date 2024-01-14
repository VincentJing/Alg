#include <iostream>

using namespace std;

// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
// 如果是，返回 true ；否则，返回 false 。

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
            return true;

        ListNode *slow = head, *fast = head, *pre = head;

        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr;

        ListNode *secontList = reverse(slow);

        while (head && secontList)
        {
            if (head->val != secontList->val)
                return false;

            head = head->next;
            secontList = secontList->next;
        }

        return true;
    }

    ListNode *reverse(ListNode *root)
    {
        if (root == nullptr || root->next == nullptr)
            return root;

        ListNode *left = root, *right = left->next;
        left->next = nullptr;

        ListNode *tmp;

        while (right)
        {
            tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }

        return left;
    }
};
