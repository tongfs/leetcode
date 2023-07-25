/*
 * @lc app=leetcode.cn id=154 lang=cpp
 * @lcpr version=21910
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        while (nums.size() > 1 && nums.back() == nums[0])
            nums.pop_back();
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        return nums[(l + 1) % nums.size()];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,0,1]\n
// @lcpr case=end

 */

