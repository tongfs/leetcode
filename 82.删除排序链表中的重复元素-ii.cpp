/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1, head), p = dummy;
        while (p->next) {
            auto a = p->next, b = a->next, t = a;
            while (b && a->val == b->val) a = b, b = b->next;
            if (a != t) p->next = b;
            else p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

