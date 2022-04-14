/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_price = INT_MAX;
        for (auto p : prices) {
            max_profit = max(max_profit, p - min_price);
            min_price = min(min_price, p);
        }
        return max_profit;
    }
};
// @lc code=end

