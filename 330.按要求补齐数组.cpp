/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0, res = 0;
        long range = 1; // range 表示 [0, range) 范围的数都可以表示
        while (range <= n)
            if (i < nums.size() && nums[i] <= range) {
                range += nums[i ++ ];
            } else {
                range <<= 1;
                res ++ ;
            } 
        return res;
    }
};
// @lc code=end

