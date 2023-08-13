/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=21910
 *
 * [72] 编辑距离
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        word1 = ' ' + word1, word2 = ' ' + word2;

        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++) f[i][0] = i;
        for (int i = 0; i <= m; i++) f[0][i] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + (word1[i] != word2[j]));
            }
        }

        return f[n][m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */

