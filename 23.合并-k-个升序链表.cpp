/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=21910
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
        for (auto& list : lists) if (list) heap.push(list);
        
        auto dummy = new ListNode(), p = dummy;
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            p = p->next = t;
            if (t->next) heap.push(t->next);
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

