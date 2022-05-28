/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return greedy(nums);
    }

    // 解法一：动态规划
    int dp(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);

        for (int i = 0; i < n; i ++ ) {
            f[i] = 1;
            for (int j = 0; j < i; j ++ )
                if (nums[j] < nums[i])
                    f[i] = max(f[i], f[j] + 1);
        }

        int res = 1;
        for (auto x: f) res = max(res, x);
        return res;
    }

    // 解法二：贪心 + 二分
    int greedy(vector<int>& nums) {
        vector<int> q;
        for (int i = 0; i < nums.size(); i ++ ) {
            int l = 0, r = q.size();
            while (l < r) {
                int mid = l + r >> 1;
                if (q[mid] >= nums[i]) r = mid;
                else l = mid + 1;
            }
            if (l == q.size()) q.push_back(nums[i]);
            else q[l] = nums[i];
        }

        return q.size();
    }
};
// @lc code=end

