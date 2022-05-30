/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    // 区间 dp 问题
    // f[i][j]: 戳破 i+1 ~ j-1 之间的气球所获得的最大硬币数量
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i ++ ) a[i + 1] = nums[i];
        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        for (int len = 3; len <= n + 2; len ++ )
            for (int l = 0; l + len - 1 < n + 2; l ++ ) {
                int r = l + len - 1;
                for (int k = l + 1; k < r; k ++ )
                    f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
            }
        return f[0][n + 1];
    }
};
// @lc code=end

