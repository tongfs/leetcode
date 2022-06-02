/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(), cur = dummy;
        for (int t = 0; l1 || l2 || t; )
        {
            if (l1) t += l1->val, l1 = l1->next;
            if (l2) t += l2->val, l2 = l2->next;
            cur = cur->next = cur->next = new ListNode(t % 10);
            t /= 10;
        }
        return dummy->next;
    }
};
// @lc code=end

