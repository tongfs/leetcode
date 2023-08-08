/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 * @lcpr version=21910
 *
 * [1749] 任意子数组和的绝对值的最大值
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min_sum = INT_MAX, max_sum = INT_MIN;
        for (int i = 0, t1 = 0, t2 = 0; i < nums.size(); i++) {
            t1 += nums[i], t2 += nums[i];
            max_sum = max(max_sum, t1);
            min_sum = min(min_sum, t2);
            t1 = max(t1, 0), t2 = min(t2, 0);
        }
        return max(-min_sum, max_sum);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-3,2,3,-4]\n
// @lcpr case=end

// @lcpr case=start
// [2,-5,1,-4,3,-2]\n
// @lcpr case=end

 */

