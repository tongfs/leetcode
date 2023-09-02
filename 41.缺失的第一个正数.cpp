/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=21910
 *
 * [41] 缺失的第一个正数
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[i] != INT_MIN && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (i + 1 != nums[i])
                return i + 1;
        return n + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2147483648]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */

