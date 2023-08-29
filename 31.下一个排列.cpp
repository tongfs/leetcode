/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=21910
 *
 * [31] 下一个排列
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while (k && nums[k - 1] >= nums[k]) k--;
        if (k) {
            int t = nums.size() - 1;
            while (nums[k - 1] >= nums[t]) t--;
            swap(nums[k - 1], nums[t]);
        }
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

