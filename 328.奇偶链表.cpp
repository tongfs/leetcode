/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        auto cur = head;
        auto dummy = new ListNode(), tail = dummy;
        
        while (cur->next && cur->next->next) {
            auto t = cur->next;
            cur = cur->next = t->next;
            tail = tail->next = t;
        }

        if (cur->next) tail = tail->next = cur->next;
        cur->next = dummy->next;
        tail->next = nullptr;

        return head;
    }
};
// @lc code=end

