/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=21910
 *
 * [695] 岛屿的最大面积
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int n, m, res = 0;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int t = dfs(i, j, grid);
                    res = max(res, t);
                }
            }
        }

        return res;
    }

    int dfs(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = 2;

        int ans = 1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 1)
                ans += dfs(a, b, grid);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */

