/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        typedef unsigned long long ULL;
        int n = s.size(), m = t.size();
        s = ' ' + s, t = ' ' + t;

        // f[i][j]: s[1~i]的所有和t[1~j]相等的子序列的个数
        vector<vector<ULL>> f(n + 1, vector<ULL>(m + 1));

        for (int i = 0; i <= n; i ++ ) f[i][0] = 1;
        for (int j = 1; j <= m; j ++ )
            for (int i = j; i <= n; i ++ ) {
                f[i][j] = f[i - 1][j];  // 不选s[i]
                if (s[i] == t[j]) f[i][j] += f[i - 1][j - 1];
            }
        
        return f[n][m];
    }
};
// @lc code=end

