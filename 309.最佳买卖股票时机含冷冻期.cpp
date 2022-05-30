/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), INF = 0x3f3f3f3f;
        vector<vector<int>> f(2, vector<int>(3, -INF));
        f[0][0] = 0, f[0][1] = -prices[0];
        for (int i = 1; i < n; i ++ ) {
            f[i & 1][0] = max(f[(i - 1 & 1)][0], f[i - 1 & 1][2]);
            f[i & 1][1] = max(f[i - 1 & 1][0] - prices[i], f[i - 1 & 1][1]);
            f[i & 1][2] = f[i - 1 & 1][1] + prices[i];
        }
        return max(f[n - 1 & 1][0], max(f[n - 1 & 1][1], f[n - 1 & 1][2]));
    }
};
// @lc code=end

