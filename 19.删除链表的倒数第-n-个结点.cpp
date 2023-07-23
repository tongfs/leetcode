/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=21910
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for (auto p = head; p; p = p->next) len++;

        auto dummy = new ListNode(-1, head), cur = dummy;
        for (int i = 0; i < len - n; i++) cur = cur->next;
        cur->next = cur->next->next;
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

