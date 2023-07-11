/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=21909
 *
 * [32] 最长有效括号
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk; // 存放左括号的下标
        int res = 0;

        for (int i = 0, st = -1; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            else {
                if (stk.size()) {
                    stk.pop();
                    if (stk.size()) res = max(res, i - stk.top());
                    else res = max(res, i - st);
                } else st = i;
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
