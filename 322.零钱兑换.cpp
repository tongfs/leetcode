/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=21910
 *
 * [322] 零钱兑换
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, 0x3f3f3f3f);
        f[0] = 0;
        for (int i = 0; i < coins.size(); i++)
            for (int j = coins[i]; j <= amount; j++)
                f[j] = min(f[j], f[j - coins[i]] + 1);
        return f[amount] == 0x3f3f3f3f ? -1 : f[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

