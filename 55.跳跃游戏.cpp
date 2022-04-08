/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // return dp(nums);
        return greedy(nums);
    }

    // 方法一：动态规划
    bool dp(vector<int>& nums) {
        int n = nums.size();

        vector<bool> f = vector<bool>(n);
        f[n - 1] = true;

        for (int i = n - 2; i >= 0; i -- ) {
            for (int j = 1; j <= nums[i]; j ++ ) {
                if (i + j < n) {
                    f[i] = f[i] || f[i + j];
                    if (f[i]) break;
                }
            }
        }
        
        return f[0];
    }

    // 方法二：贪心
    bool greedy(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, r = 0; i < n && r < n - 1; i ++ ) {
            if (i > r) return false;
            r = max(r, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end

