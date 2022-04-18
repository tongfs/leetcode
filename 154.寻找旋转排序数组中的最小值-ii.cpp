/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int t = nums[0];
        while (nums.back() == t && nums.size() > 1) nums.pop_back();

        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= t) l = mid;
            else r = mid - 1;
        }

        return nums[(l + 1) % n];
    }
};
// @lc code=end

