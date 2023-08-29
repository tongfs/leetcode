/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=21910
 *
 * [1143] 最长公共子序列
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        s1 = ' ' + s1, s2 = ' ' + s2;

        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1;j <= m; j++) {
                if (s1[i] == s2[j])  f[i][j] = f[i - 1][j - 1] + 1;
                else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[n][m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */

