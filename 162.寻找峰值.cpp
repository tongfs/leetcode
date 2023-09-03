/*
 * @lc app=leetcode.cn id=162 lang=cpp
 * @lcpr version=21910
 *
 * [162] 寻找峰值
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */

