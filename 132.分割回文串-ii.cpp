/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;

        // f[i][j]: s[i~j]是否是回文串
        vector<vector<bool>> f(n + 1, vector<bool>(n + 1));
        for (int j = 1; j <= n; j ++ )
            for (int i = 1; i <= j; i ++ )
                if (i == j) f[i][j] = true;
                else if (s[i] == s[j])
                    if (i + 1 > j - 1 || f[i + 1][j - 1]) f[i][j] = true;
                
        // g[i]: s[1~i]分割成的子串都是回文串时最小的分割次数
        vector<int> g(n + 1, n);
        g[0] = 0;
        for (int i = 1; i <= n; i ++ )
            for (int j = i; j <= n; j ++ )
                if (f[i][j])
                    g[j] = min(g[j], g[i - 1] + 1);
        
        return g[n] - 1;
    }

};
// @lc code=end
