/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> f(2, vector<int>(2));

        int res = 0;
        
        // 不偷1号房屋
        for (int i = 1; i < n; i ++ ) {
            f[i & 1][0] = max(f[(i - 1) & 1][0], f[(i - 1) & 1][1]);
            f[i & 1][1] = f[(i - 1) & 1][0] + nums[i];
        }
        res = max(f[(n - 1) & 1][0], f[(n - 1) & 1][1]);

        // 偷1号房屋（其实也包含了不偷的情况，最后只取不偷n号房屋的结果）
        f[0][1] = nums[0], f[0][0] = 0;
        for (int i = 1; i < n; i ++ ) {
            f[i & 1][0] = max(f[(i - 1) & 1][0], f[(i - 1) & 1][1]);
            f[i & 1][1] = f[(i - 1) & 1][0] + nums[i];
        }
        res = max(res, f[(n - 1) & 1][0]);

        return res;
    }
};
// @lc code=end

