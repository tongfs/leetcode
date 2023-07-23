/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=21910
 *
 * [200] 岛屿数量
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
        return res;   
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '2';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (~a && a < n && ~b && b < m && grid[a][b] == '1')
                dfs(grid, a, b);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */

