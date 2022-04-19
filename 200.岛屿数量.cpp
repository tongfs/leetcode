/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<int>> grid;

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    res ++ ;
                }

        return res;
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '2';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == '1')
                dfs(a, b, grid);
        }
    }
};
// @lc code=end

