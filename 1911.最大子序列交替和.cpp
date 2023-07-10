/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 * @lcpr version=21909
 *
 * [1911] 最大子序列交替和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        return method2(nums);
    }

    /**
     * dp
     */
    long long method1(vector<int>& nums) {
        int n = nums.size();
        // f[i][0/1]: nums[0~i-1] 的最大交替和，且当前为偶数/奇数下标
        vector<vector<long long>> f(n + 1, vector<long long>(2));
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + nums[i - 1]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - nums[i - 1]);
        }
        return f[n][0];
    }

    /**
     * rolling array
     */
    long long method2(vector<int>& nums) {
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
