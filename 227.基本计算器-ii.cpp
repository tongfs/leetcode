/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    stack<int> num;
    stack<char> op;

    int calculate(string s) {
        unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

        for (int i = 0; s[i]; i ++ ) {
            if (s[i] == ' ') continue;
            auto c = s[i];
            if (isdigit(c)) {
                int j = i, x = 0;
                while (s[j] && isdigit(s[j])) x = x * 10 - '0' + s[j ++ ];
                num.push(x);
                i = j - 1;
            } else {
                while (op.size() && pr[op.top()] >= pr[c]) eval();
                op.push(c);
            }
        }

        while (op.size()) eval();
        return num.top();
    }

    void eval() {
        auto b = num.top(); num.pop();
        auto a = num.top(); num.pop();
        auto c = op.top(); op.pop();

        if (c == '+') a += b;
        else if (c == '-') a -= b;
        else if (c == '*') a *= b;
        else a /= b;

        num.push(a);
    }
};
// @lc code=end

