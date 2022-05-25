/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        for (auto t = head; t; t = t->next) n ++ ;
        int m = n / 2;

        auto dummy = new ListNode();
        for (int i = 0; i < m; i ++ ) {
            auto t = head;
            head = head->next;
            t->next = dummy->next;
            dummy->next = t;
        }

        if (n & 1) head = head->next;
        for (auto p = dummy->next, q = head; p; p = p->next, q = q->next)
            if (p->val != q->val)
                return false;

        return true;
    }
};
// @lc code=end

