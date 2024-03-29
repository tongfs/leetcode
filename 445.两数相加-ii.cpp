/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=21910
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        int t = 0;
        auto dummy = new ListNode(), cur = dummy;
        while (l1 || l2 || t) {
            if (l1) t += l1->val, l1 = l1->next;
            if (l2) t += l2->val, l2 = l2->next;
            cur = cur->next = new ListNode(t % 10);
            t /= 10;
        }
        return reverse(dummy->next);
    }

    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr;
        auto a = head, b = a->next;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        head->next = nullptr;
        return a;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */
