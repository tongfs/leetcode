/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=21910
 *
 * [121] 买卖股票的最佳时机
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_price = INT_MAX;
        for (auto x : prices) {
            min_price = min(min_price, x);
            max_profit = max(max_profit, x - min_price);
        }
        return max_profit;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

