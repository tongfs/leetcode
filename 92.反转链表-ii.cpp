/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=21910
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1, head), p = dummy;
        for (int i = 1; i < left; i++) p = p->next;
        auto a = p->next, b = a->next;
        for (int i = 0; i < right - left; i++) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        p->next->next = b;
        p->next = a;
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */

