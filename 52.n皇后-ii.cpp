/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int n, res = 0;
    vector<bool> col, dg, udg;

    int totalNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(n * 2);

        dfs(0);
        return res;
    }

    void dfs(int u) {
        if (u == n) {
            res ++ ;
            return;
        }

        for (int i = 0; i < n; i ++ ) {
            if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
                col[i] = dg[u + i] = udg[n - u + i] = true;
                dfs(u + 1);
                col[i] = dg[u + i] = udg[n - u + i] = false;
            }
        }
    }
};
// @lc code=end
