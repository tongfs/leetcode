/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> f(n, vector<int>(m, INT_MAX));

        for (int i = n - 1; i >= 0; i -- )
            for (int j = m - 1; j >= 0; j -- )
                if (i == n - 1 && j == m - 1) f[i][j] = max(1, 1 - dungeon[i][j]);
                else {
                    if (i + 1 < n) f[i][j] = f[i + 1][j] - dungeon[i][j];
                    if (j + 1 < m) f[i][j] = min(f[i][j], f[i][j + 1] - dungeon[i][j]);
                    f[i][j] = max(1, f[i][j]);
                }
        
        return f[0][0];
    }
};
// @lc code=end

