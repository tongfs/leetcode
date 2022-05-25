/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<string> expr;

    vector<int> diffWaysToCompute(string str) {
        // 预处理
        for (int i = 0; str[i]; i ++ ) {
            if (isdigit(str[i])) {
                int j = i, x = 0;
                while (str[j] && isdigit(str[j])) x = x * 10 + str[j ++ ] - '0';
                i = j - 1;
                expr.push_back(to_string(x));
            } else expr.push_back(str.substr(i, 1));
        }

        // 分治
        return dfs(0, expr.size() - 1);
    }

    vector<int> dfs(int l, int r) {
        if (l == r) return {stoi(expr[l])};
        
        vector<int> res;
        for (int i = l + 1; i < r; i += 2) {
            auto n = dfs(l, i - 1), m = dfs(i + 1, r);
            for (auto x: n)
                for (auto y: m) {
                    int t;
                    char c = expr[i][0];
                    if (c == '+') t = x + y;
                    else if (c == '-') t = x - y;
                    else t = x * y;
                    res.push_back(t);
                }
        }
        return res;
    }
};
// @lc code=end

