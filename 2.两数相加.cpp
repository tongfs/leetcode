/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t = 0;
        auto dummy = new ListNode(), cur = dummy;
        while (l1 || l2 || t)
        {
            if (l1) t += l1->val, l1 = l1->next;
            if (l2) t += l2->val, l2 = l2->next;
            cur->next = new ListNode(t % 10);
            cur = cur->next;
            t /= 10;
        }
        
        return dummy->next;
    }
};
// @lc code=end

