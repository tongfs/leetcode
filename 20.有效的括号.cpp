/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=21910
 *
 * [20] 有效的括号
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> stk;
        for (auto c : s) {
            if (map.count(c)) stk.push(c);
            else if (stk.size() && map[stk.top()] == c) stk.pop();
            else return false;
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

