/*
 * @lc app=leetcode.cn id=123 lang=cpp
 * @lcpr version=21910
 *
 * [123] 买卖股票的最佳时机 III
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n + 1);

        for (int i = 1, min_price = INT_MAX; i <= n; i++) {
            f[i] = max(f[i - 1], prices[i - 1] - min_price);
            min_price = min(min_price, prices[i - 1]);
        }

        int res = 0;
        for (int i = n, max_price = 0; i; i--) {
            res = max(res, f[i - 1] + max_price - prices[i - 1]);
            max_price = max(max_price, prices[i - 1]);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,5,0,0,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

