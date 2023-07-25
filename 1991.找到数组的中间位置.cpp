/*
 * @lc app=leetcode.cn id=1991 lang=cpp
 * @lcpr version=21910
 *
 * [1991] 找到数组的中间位置
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
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
// [2,3,-1,8,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,-1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

