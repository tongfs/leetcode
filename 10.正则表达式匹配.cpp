/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <iostream>
#include <vector>

using namespace std;

/* 
 * 1. 状态表示：f[i][j]: 所有 s[1~i] 和 p[1~j] 的方案中，是否存在合法方案
 * 2. 状态计算：
 *      p[j] != '*': (s[i] == p[j] || p[j] == '.') && f[i-1][j-1]
 *      p[j] == '*': 
 *          '*' 匹配零个字符：f[i][j-2]
 *          '*' 匹配一个字符：f[i-1][j-2] && s[i] == p[j-1] || p[j-1] == '.'
 *          '*' 匹配...
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;

        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;

        for (int i = 0; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
            {
                if (j + 1 <= m && p[j + 1] == '*') continue;    // 当前 p[j] 不能用
                if (i && p[j] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                } else if (p[j] == '*') {
                    f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
                }
            }

        return f[n][m];
    }
};
// @lc code=end

