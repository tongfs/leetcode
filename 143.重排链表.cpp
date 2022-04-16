/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;

        int cnt = 0;
        for (auto p = head; p; p = p->next, cnt ++ );

        int t = cnt;
        for (auto p = head; p; p = p->next) {
            if (t >= 1) t -= 2;
            else stk.push(p);
        }

        auto p = head, tail = head;
        for (; stk.size(); p = p->next->next) {
            auto t = stk.top(); stk.pop();
            t->next = p->next;
            tail = p->next = t;
        }

        if (tail->next) tail->next->next = nullptr;
    }
};
// @lc code=end

