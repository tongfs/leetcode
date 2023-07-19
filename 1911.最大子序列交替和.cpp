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
        vector<long long> f(2);
        f[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            f[0] = max(f[0], f[1] + nums[i]);
            f[1] = max(f[1], f[0] - nums[i]);
        }
        return f[0];
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
