/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=21910
 *
 * [83] 删除排序链表中的重复元素
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
        auto p = head;
        while (p) {
            auto t = p->next;
            while (t && p->val == t->val) t = t->next;
            if (p->next == t) p = t;
            else p = p->next = t;
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */

