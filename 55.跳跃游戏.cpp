/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=21910
 *
 * [55] 跳跃游戏
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, k = 0; i < n && k < n - 1; i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */

