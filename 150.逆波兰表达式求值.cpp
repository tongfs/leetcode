/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (auto& s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if (s[0] == '+') a += b;
                else if (s[0] == '-') a -= b;
                else if (s[0] == '*') a *= b;
                else a /= b;
                stk.push(a);
            } else stk.push(stoi(s));
        }

        return stk.top();
    }
};
// @lc code=end

