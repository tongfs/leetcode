/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    struct Cmp {
        bool operator()(ListNode *l1, ListNode *l2) {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return {};
        // return myMergeKLists(lists, 0, lists.size() - 1);

        // 解法二：小根堆
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        auto dummy = new ListNode(), tail = dummy;
        for (auto& l : lists) if (l) heap.push(l);
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            tail = tail->next = t;
            if (t->next) heap.push(t->next);
        }
        return dummy->next;
    }

    // 解法一：二路归并
    /* ListNode* myMergeKLists(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = l + r >> 1;
        auto l1 = myMergeKLists(lists, l, mid);
        auto l2 = myMergeKLists(lists, mid + 1, r);
        return merge2Lists(l1, l2);
    }

    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        auto dummy = new ListNode(), cur = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) cur->next = list1, list1 = list1->next;
            else cur->next = list2, list2 = list2->next;
            cur = cur->next;
        }
        if (list1) cur->next = list1;
        if (list2) cur->next = list2;
        return dummy->next;
    } */
};
// @lc code=end

