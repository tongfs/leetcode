/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int n;
    vector<bool> col, dg, udg;
    vector<string> path;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(n * 2);
        path = vector<string>(n, string(n, '.'));

        dfs(0);
        return res;
    }

    void dfs(int u) {
        if (u == n) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; i ++ ) {
            if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
                path[u][i] = 'Q';
                col[i] = dg[u + i] = udg[n - u + i] = true;
                dfs(u + 1);
                col[i] = dg[u + i] = udg[n - u + i] = false;
                path[u][i] = '.';
            }
        }
    }
};
// @lc code=end

