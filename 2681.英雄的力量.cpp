/*
 * @lc app=leetcode.cn id=2681 lang=cpp
 * @lcpr version=21910
 *
 * [2681] 英雄的力量
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());

        long long res = 0, min_sum = 0;
        for (auto x : nums) {
            res = (res + (long long) x * x % MOD * (min_sum + x)) % MOD;
            min_sum = (min_sum * 2 + x) % MOD;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */

