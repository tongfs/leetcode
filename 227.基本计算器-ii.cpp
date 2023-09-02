/*
 * @lc app=leetcode.cn id=227 lang=cpp
 * @lcpr version=21910
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
        unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int t = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    t = t * 10 - '0' + s[j++];
                num.push(t);
                i = j - 1;
            } else {
                while (op.size() && pr[op.top()] >= pr[s[i]]) eval();
                op.push(s[i]);
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



/*
// @lcpr case=start
// "3+2*2"\n
// @lcpr case=end

// @lcpr case=start
// " 3/2 "\n
// @lcpr case=end

// @lcpr case=start
// " 3+5 / 2 "\n
// @lcpr case=end

 */

