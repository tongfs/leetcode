/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (auto x: nums)
            if (x) nums[i ++ ] = x;
        while (i < nums.size()) nums[i ++ ] = 0;
    }
};
// @lc code=end

