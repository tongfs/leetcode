/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=21910
 *
 * [53] 最大子数组和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, max_sum = 0;
        for (auto x : nums) {
            max_sum += x;
            res = max(res, max_sum);
            max_sum = max(0, max_sum);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

