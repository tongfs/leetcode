/*
 * @lc app=leetcode.cn id=724 lang=cpp
 * @lcpr version=21910
 *
 * [724] 寻找数组的中心下标
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums) sum += x;
        for (int i = 0, cur = 0; i < nums.size(); i++) {
            if (cur * 2 == sum - nums[i]) return i;
            cur += nums[i];
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 7, 3, 6, 5, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */

