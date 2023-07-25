/*
 * @lc app=leetcode.cn id=328 lang=cpp
 * @lcpr version=21910
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

        auto p = head;
        auto dummy = new ListNode(), q = dummy;

        while (p->next && p->next->next) {
            auto t = p->next;
            p = p->next = t->next;
            q = q->next = t;
        }

        if (p->next) q = q->next = p->next;
        else q->next = nullptr;
        p->next = dummy->next;

        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,5,6,4,7]\n
// @lcpr case=end

 */

