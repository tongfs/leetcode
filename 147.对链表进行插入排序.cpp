/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        auto dummy = new ListNode(), tail = dummy;
        for (auto p = head; p; ) {
            auto cur = dummy, t = p->next;
            while (cur->next && cur->next->val < p->val) cur = cur->next;
            p->next = cur->next;
            cur->next = p;
            p = t;
        }
        return dummy->next;
    }
};
// @lc code=end

