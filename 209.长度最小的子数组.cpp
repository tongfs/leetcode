/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=21910
 *
 * [209] 长度最小的子数组
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0, j = 0, sum = 0; j < nums.size(); ) {
            while (sum < target && j < nums.size()) sum += nums[j++];
            while (sum >= target) res = min(res, j - i), sum -= nums[i++];
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

