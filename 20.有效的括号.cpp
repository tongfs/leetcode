/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=21909
 *
 * [20] 有效的括号
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1) return false;

        stack<char> stk;
        unordered_map<char, int> map{{'(', -1}, {')', 1},  {'[', -2},
                                     {']', 2},  {'{', -3}, {'}', 3}};
        for (auto c : s) {
            if (map[c] < 0) stk.push(c);
            else {
                if (stk.size() && map[c] + map[stk.top()] == 0) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */
