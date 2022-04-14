/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    // 前后缀分解的思想
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n + 1);

        // f[i]表示前i天中买入卖出一次的最大收益
        for (int i = 1, minp = INT_MAX; i <= n; i ++ ) {
            minp = min(minp, prices[i - 1]);
            f[i] = max(f[i - 1], prices[i - 1] - minp);
        }

        int res = 0;
        for (int i = n, maxp = 0; i; i -- ) {
            res = max(res, f[i - 1] + maxp - prices[i - 1]);
            maxp = max(maxp, prices[i - 1]);
        }

        return res;
    }
};
// @lc code=end

