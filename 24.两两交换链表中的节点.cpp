/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1, head);
        auto pre = dummy, cur = dummy->next;
        while (cur && cur->next) {
            auto p = cur->next, q = p->next;
            cur->next = q;
            p->next = cur;
            pre->next = p;
            pre = cur;
            cur = q;
        }
        return dummy->next;
    }
};
// @lc code=end

