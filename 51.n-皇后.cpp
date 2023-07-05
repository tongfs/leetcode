/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=21909
 *
 * [51] N 皇后
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<bool> col, dg, udg;
    vector<string> path;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n);
        dg = udg = vector<bool>(n * 2);
        path = vector<string>(n, string(n, '.'));

        dfs(0, n);
        return res;
    }

    void dfs(int u, int n) {
        if (u == n) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
                path[u][i] = 'Q';
                col[i] = dg[u + i] = udg[n - u + i] = true;
                dfs(u + 1, n);
                col[i] = dg[u + i] = udg[n - u + i] = false;
                path[u][i] = '.';
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
