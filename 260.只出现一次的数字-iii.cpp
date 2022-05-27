/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int p = 0, k = 0;
        for (auto x: nums) p ^= x;
        while ((p >> k & 1) == 0) k ++ ;
        return {get(nums, k, 0), get(nums, k, 1)};
    }

    int get(vector<int>& nums, int k, int t) {
        int res = 0;
        for (auto x: nums)
            if ((x >> k & 1) == t)
                res ^= x;
        return res;
    }
};
// @lc code=end

