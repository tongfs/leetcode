/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n, 1);
        for (int i = 1; i < n; i ++ ) p[i] = p[i - 1] * nums[i - 1];
        for (int i = n - 1, s = 1; i >= 0; i -- ) {
            p[i] *= s;
            s *= nums[i];
        }
        return p;
    }
};
// @lc code=end

