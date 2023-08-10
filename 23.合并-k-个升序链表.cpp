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
        return method2(lists);
    }

    /**
     * heap
     */
    ListNode* method1(vector<ListNode*>& lists) {
        auto cmp = [&] (const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
        for (auto& list : lists) if (list) heap.push(list);

        auto dummy = new ListNode(), cur = dummy;
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            if (t->next) heap.push(t->next);
            cur = cur->next = t;
        }

        return dummy->next;
    }

    /**
     * conquer
     */
    ListNode* method2(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return myMergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* myMergeKLists(vector<ListNode*> lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = l + r >> 1;
        auto l1 = myMergeKLists(lists, l, mid);
        auto l2 = myMergeKLists(lists, mid + 1, r);
        return merge2Lists(l1, l2);
    }

    ListNode* merge2Lists(ListNode* l, ListNode* r) {
        auto dummy = new ListNode(), cur = dummy;
        while (l && r) {
            if (l->val < r->val) cur = cur->next = l, l = l->next;
            else cur = cur->next = r, r = r->next;
        }
        if (l) cur->next = l;
        if (r) cur->next = r;
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

