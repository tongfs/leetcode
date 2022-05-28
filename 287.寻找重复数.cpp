/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[slow];
        while (slow != fast) slow = nums[slow], fast = nums[nums[fast]];
        int t = 0;
        while (t != slow) t = nums[t], slow = nums[slow];
        return t;
    }
};
// @lc code=end

