/*
 * @lc app=leetcode.cn id=52 lang=cpp
 * @lcpr version=21909
 *
 * [52] N 皇后 II
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int res = 0;
    vector<bool> col, dg, udg;

    int totalNQueens(int n) {
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n);

        dfs(0, n);
        return res;
    }
    
    void dfs(int u, int n) {
        if (u == n) {
            res++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
                col[i] = dg[u + i] = udg[n - u + i] = true;
                dfs(u + 1, n);
                col[i] = dg[u + i] = udg[n - u + i] = false;
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
