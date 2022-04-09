/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x) {
        auto l1 = new ListNode(), t1 = l1;
        auto l2 = new ListNode(), t2 = l2;

        for (auto p = head; p; p = p->next) {
            if (p->val < x) t1 = t1->next = p;
            else t2 = t2->next = p;
        }

        t1->next = l2->next;
        t2->next = nullptr;
        return l1->next;
    }
};
// @lc code=end

