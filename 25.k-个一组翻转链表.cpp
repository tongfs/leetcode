/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

#include <iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1, head);
        for (auto p = dummy; ; ) {
            auto t = p;
            for (int i = 0; i < k && t; i ++ ) t = t->next;
            if (!t) break;
            auto a = p->next, b = a->next;
            for (int i = 0; i < k - 1; i ++ ) {
                auto c = b->next;
                b->next = a;
                a = b, b = c;
            }
            auto c = p->next;
            c->next = b, p->next = a;
            p = c;
        }
        return dummy->next;
    }
};
// @lc code=end

