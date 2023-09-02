/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=21910
 *
 * [160] 相交链表
 */
#include "mylib.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0, m = 0;
        for (auto p = headA; p; p = p->next) n++;
        for (auto p = headB; p; p = p->next) m++;
        if (n > m) swap(headA, headB);
        auto a = headA, b = headB;
        for (int i = 0; i < abs(n - m); i++) b = b->next;
        while (a && a != b) a = a->next, b = b->next;
        return a;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */

