/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

#include "mylib.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recursive(head);
    }

    // 解法一：迭代带头节点
    ListNode* iteration1(ListNode* head) {
        auto dummy1 = new ListNode(-1, head);
        auto dummy2 = new ListNode();

        while (dummy1->next) {
            auto p = dummy1->next, t = p->next;
            p->next = dummy2->next;
            dummy2->next = p;
            dummy1->next = t;
        }

        return dummy2->next;
    }

    // 解法二：迭代不带头节点
    ListNode* iteration2(ListNode* head) {
        if (!head) return nullptr;
        auto a = head, b = a->next;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        head->next = nullptr;
        return a;
    }

    // 解法三：递归
    ListNode* recursive(ListNode* head) {
        if (!head || !head->next) return head;
        auto t = recursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return t;
    }
};
// @lc code=end

