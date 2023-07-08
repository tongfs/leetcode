/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=21909
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) { 
        auto dummy = new ListNode(-1, head);
        auto pre = dummy, cur = dummy->next;
        while (cur && cur->next) {
            auto p = cur->next, q = p->next;
            p->next = cur;
            pre->next = p;
            cur->next = q;
            pre = cur, cur = q;
        }
        return dummy->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
