/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, 1e8);
        f[0] = 0;
        for (int coin: coins)
            for (int j = coin; j <= amount; j ++ )
                f[j] = min(f[j], f[j - coin] + 1);
        return f[amount] == 1e8 ? -1 : f[amount];
    }
};
// @lc code=end

