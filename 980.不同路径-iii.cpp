/*
 * @lc app=leetcode.cn id=980 lang=cpp
 * @lcpr version=21910
 *
 * [980] 不同路径 III
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<int>> grid;

    int uniquePathsIII(vector<vector<int>>& _grid) {
        grid = _grid;
        n = grid.size();
        m = grid[0].size();

        int sx, sy, k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    k++;
                } else if (grid[i][j] == 1) {
                    sx = i, sy = j;
                    k++;
                }
            }
        }

        return dfs(sx, sy, 0, k);
    }

    int dfs(int x, int y, int u, int k) {
        if (grid[x][y] == 2) {
            if (u == k) return 1;
            return 0;
        }

        int res = 0, t = grid[x][y];
        grid[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && (grid[a][b] == 0 || grid[a][b] == 2))
                res += dfs(a, b, u + 1, k);
        }
        grid[x][y] = t;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,0,0,0],[0,0,0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[2,0]]\n
// @lcpr case=end

 */

