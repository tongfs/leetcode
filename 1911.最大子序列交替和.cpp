/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 * @lcpr version=21910
 *
 * [1911] 最大子序列交替和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = nums[0], odd = 0;
        for (int i = 1; i < nums.size(); i++) {
            even = max(even, odd + nums[i]);
            odd = max(odd, even - nums[i]);
        }
        return even;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [6,2,1,2,4,5]\n
// @lcpr case=end

 */

