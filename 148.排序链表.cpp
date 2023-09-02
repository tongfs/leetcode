/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=21910
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++;

        auto dummy = new ListNode(), cur = dummy;
        for (int i = 1; i < n; i *= 2) {
            auto p = head, q = head;
            for (int j = 1; j <= n; j += i * 2) {
                for (int k = 0; k < i && q; k++) q = q->next;
                int l = 0, r = 0;
                while (l < i && r < i && q) {
                    if (p->val < q->val) cur = cur->next = p, p = p->next, l++;
                    else cur = cur->next = q, q = q->next, r++;
                }
                while (l < i && p) cur = cur->next = p, p = p->next, l++;
                while (r < i && q) cur = cur->next = q, q = q->next, r++;
                p = q;
            }
            head = dummy->next;
            dummy->next = cur->next = nullptr;
            cur = dummy;
        }

        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

