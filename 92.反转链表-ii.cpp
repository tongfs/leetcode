/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1, head), p = dummy;
        for (int i = 1; i < left; i ++ ) p = p->next;
        
        auto a = p->next, b = a->next;
        for (int i = 0; i < right - left; i ++ ) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        p->next->next = b;
        p->next = a;

        return dummy->next;
    }
};
// @lc code=end

