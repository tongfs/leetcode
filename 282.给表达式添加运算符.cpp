/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int target, n;
    vector<string> res;
    string num, path;

    vector<string> addOperators(string _num, int _target) {
        target = _target, num = _num, n = num.size();
        dfs(0, 0, 0);
        return res;
    }

    /*
     * u: 已经处理了几个数
     * t: 当前表达式的计算值
     * mul: 最后一个连乘串的计算值
     */

    void dfs(int u, long t, long mul) {
        if (u == n) {
            if (t == target) res.push_back(path);
            return;
        }

        int idx = path.size();
        if (u) path.push_back(' ');

        long val = 0;
        for (int i = u; i < n && (i == u || num[u] != '0'); i ++ ) {
            val = val * 10 + num[i] - '0';
            path.push_back(num[i]);
            if (!u) dfs(i + 1, val, val);
            else {
                path[idx] = '+', dfs(i + 1, t + val, val);
                path[idx] = '-', dfs(i + 1, t - val, -val);
                path[idx] = '*', dfs(i + 1, t - mul + mul * val, mul * val);
            }
        }

        path.resize(idx);
    }
};
// @lc code=end

