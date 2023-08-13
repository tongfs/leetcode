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
        int res = INT_MIN, cur_sum = 0;
        for (auto x : nums) {
            cur_sum += x;
            res = max(res, cur_sum);
            cur_sum = max(cur_sum, 0);
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

