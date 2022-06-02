/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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
    ListNode* h;

    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        int res, k = 1;
        for (auto p = h; p; p = p->next, ++ k)
            if (rand() % k == 0) res = p->val;
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

