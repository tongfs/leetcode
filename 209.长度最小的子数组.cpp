/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;

        for (int i = 0, j = 0, sum = 0; i < nums.size(); i ++ ) {
            while (sum < target && j < nums.size()) sum += nums[j ++ ];
            if (sum >= target) res = min(res, j - i), sum -= nums[i];
        }

        if (res == INT_MAX) res = 0;
        return res;
    }
};
// @lc code=end

