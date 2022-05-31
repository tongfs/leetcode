/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> h, f;
    int n, m;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        h = matrix;
        f = vector<vector<int>>(n, vector<int>(m));
        
        int res = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                res = max(res, dfs(i, j));
        return res;
    }

    int dfs(int x, int y) {
        if (f[x][y]) return f[x][y];

        f[x][y] = 1;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && h[a][b] > h[x][y])
                f[x][y] = max(f[x][y], dfs(a, b) + 1);
        }

        return f[x][y];
    }
};
// @lc code=end

