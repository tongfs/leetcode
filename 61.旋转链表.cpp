/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;

        auto tail = head;
        int cnt = 1;
        while (tail->next) tail = tail->next, cnt ++ ;
        k %= cnt;

        auto p = head;
        for (int i = 0; i < cnt - k - 1; i ++ ) p = p->next;
        tail->next = head;
        auto res = p->next;
        p->next = nullptr;

        return res;
    }
};
// @lc code=end

