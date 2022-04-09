/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        auto p = head;
        while (p && p->next) {
            if (p->val == p->next->val) p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};
// @lc code=end

