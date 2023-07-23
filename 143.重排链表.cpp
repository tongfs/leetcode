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
        stack<ListNode*> stk;
        
        int cnt = 0;
        for (auto p = head; p; p = p->next) cnt++;
        
        int t = cnt;
        for (auto p = head; p; p = p->next) {
            if (t >= 1) t -= 2;
            else stk.push(p);
        }

        auto p = head;
        for (; stk.size(); p = p->next->next) {
            auto t = stk.top();
            stk.pop();
            t->next = p->next;
            p->next = t;
        }

        if (p) p->next = nullptr;
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

