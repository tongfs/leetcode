/*
 * @lc app=leetcode.cn id=81 lang=cpp
 * @lcpr version=21910
 *
 * [81] 搜索旋转排序数组 II
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        while (nums.size() > 1 && nums[0] == nums.back()) nums.pop_back();

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        if (nums[0] > target) l++, r = nums.size() - 1;
        else l = 0;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return nums[r] == target;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,6,0,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,5,6,0,0,1,2]\n3\n
// @lcpr case=end

 */

