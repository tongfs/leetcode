/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(2, vector<int>(2));
        f[0][1] = nums[0];

        for (int i = 1; i < n; i ++ ) {
            f[i & 1][0] = max(f[(i - 1) & 1][0], f[(i - 1) & 1][1]);
            f[i & 1][1] = f[(i - 1) & 1][0] + nums[i];
        }

        return max(f[(n - 1) & 1][0], f[(n - 1) & 1][1]);
    }
};
// @lc code=end

