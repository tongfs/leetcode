/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f = 1, g = 1, res = INT_MIN;
        for (auto x: nums) {
            int s = f * x, t = g * x;
            f = max(x, max(s, t));
            g = min(x, min(s, t));
            res = max(res, f);
        }
        return res;
    }
};
// @lc code=end

