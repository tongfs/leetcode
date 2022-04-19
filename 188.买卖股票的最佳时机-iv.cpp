/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    /* 
     * n为数组长度，如果k>=n/2，则可以交易无限次
     *
     * f[i][j]: 过了i天，完成了j笔交易，获得的最大价值
     * g[i][j]: 过了i天，正在进行第j笔交易，获得的最大价值
     *      f[i][j] = max(f[i-1][j], g[i-1][j] + p[i-1])
     *      g[i][j] = max(g[i-1][j], f[i-1][j-1] - p[i-1])
     */
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> f(n + 1, vector<int>(k + 1, -1e8));
        vector<vector<int>> g(n + 1, vector<int>(k + 1, -1e8));
        f[0][0] = 0;

        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j <= k; j ++ ) {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] + prices[i - 1]);
                g[i][j] = g[i - 1][j];
                if (j) g[i][j] = max(g[i][j], f[i - 1][j - 1] - prices[i - 1]);
                res = max(res, f[i][j]);
            }
        }

        // 优化成一维
        /* for (int i = 1; i <= n; i ++ ) {
            for (int j = k; j >= 0; j -- ) {
                f[j] = max(f[j], g[j] + prices[i - 1]);
                if (j) g[j] = max(g[j], f[j - 1] - prices[i - 1]);
                res = max(res, f[j]);
            }
        } */

        return res;
    }
};
// @lc code=end

