/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i ++ )
            for (auto x: nums)
                if (i - x >= 0 && f[i - x] <= INT_MAX - f[i])
                    f[i] += f[i - x];
        return f[target];
    }
};
// @lc code=end

