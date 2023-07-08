/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=21909
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
        return method1(lists);
    }

    /**
     * heap
     */
    ListNode* method1(vector<ListNode*> lists) {
        auto cmp = [&](const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
        for (auto l : lists) if (l) heap.push(l);
        auto dummy = new ListNode(), cur = dummy;
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            cur = cur->next = t;
            if (t->next) heap.push(t->next);
        }

        return dummy->next;
    }

    /**
     * merge
     */
    ListNode* method2(vector<ListNode*> lists) {
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

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(), cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) cur = cur->next = l1, l1 = l1->next;
            else cur = cur->next = l2, l2 = l2->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
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
