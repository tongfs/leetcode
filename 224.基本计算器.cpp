/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    stack<int> num;
    stack<char> op;

    int calculate(string s) {
        bool flag = true;

        for (int i = 0; s[i]; i ++ ) {
            char c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)) {
                int x = 0, j = i;
                while (s[j] && isdigit(s[j]))
                    x = x * 10 - '0' + s[j ++ ];
                num.push(x);
                i = j - 1;
            } else if (c == '(') {
                op.push(c);
                flag = true;
                continue;
            } else if (c == ')') {
                while (op.top() != '(') eval();
                op.pop();
            } else {
                if (c == '-' && flag) num.push(0);
                while (op.size() && op.top() != '(') eval();
                op.push(c);
            }
            flag = false;
        }

        while (op.size()) eval(); 
        return num.top();
    }

    void eval() {
        auto b = num.top(); num.pop();
        auto a = num.top(); num.pop();
        auto c = op.top(); op.pop();

        if (c == '+') a += b;
        else a -= b;

        num.push(a);
    }
};
// @lc code=end

