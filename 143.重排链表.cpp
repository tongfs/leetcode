/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=21910
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
        auto dummy = new ListNode();
        auto slow = head, fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto t = slow->next;
        while (t) {
            auto p = t;
            t = t->next;
            p->next = dummy->next;
            dummy->next = p;
        }

        auto cur = head;
        while (dummy->next) {
            auto p = dummy->next;
            dummy->next = p->next;
            p->next = cur->next;
            cur->next = p;
            cur = p->next;
        }

        if (cur) cur->next = nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

