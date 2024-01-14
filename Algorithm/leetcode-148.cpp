#include <iostream>

using namespace std;

// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

//  Definition for singly-linked list.
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
    // 冒泡 O(n*n)
    ListNode *sortList1(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *res = new ListNode(0, head);
        ListNode *pre = res;

        ListNode *lastNode = nullptr;

        while (res->next != lastNode)
        {
            pre = res;

            ListNode *left = pre->next;
            ListNode *right = left->next;

            while (right != lastNode)
            {
                if (left->val > right->val)
                {
                    int tmp = right->val;
                    right->val = left->val;
                    left->val = tmp;
                }

                pre = pre->next;
                left = pre->next;
                right = left ? left->next : nullptr;
            }

            lastNode = left;
        }

        return res->next;
    }

    // 归并排序
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *res = head;
        ListNode *slow = head, *fast = head;

        ListNode *tmp = slow;
        // 找出链表的中点，使用快慢指针
        while (fast && fast->next)
        {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *l1 = head;
        ListNode *l2 = slow;
        // 断开链表
        tmp->next = nullptr;

        l1 = sortList(l1);
        l2 = sortList(l2);
        return merge(l1, l2);
    }

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2);

        ListNode *res = list1;
        ListNode *pre = list1;
        list1 = list1->next;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                pre->next = list1;
                pre = pre->next;
                list1 = list1->next;
            }
            else
            {
                pre->next = list2;
                pre = pre->next;
                list2 = list2->next;
            }
        }

        pre->next = list1 ? list1 : list2;

        return res;
    }
};