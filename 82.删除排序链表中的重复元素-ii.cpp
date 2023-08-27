/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=21910
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1, head), p = dummy;
        while (p->next) {
            auto a = p->next, b = a->next;
            while (b && a->val == b->val) a = b, b = b->next;
            if (p->next == a) p = a;
            else p->next = b;
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */

