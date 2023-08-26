/*
 * @lc app=leetcode.cn id=912 lang=cpp
 * @lcpr version=21910
 *
 * [912] 排序数组
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quick_sort(vector<int>& nums, int l, int r) {
        if (l == r) return;

        int i = l - 1, j = r + 1, x = nums[l + r >> 1];
        while (i < j) {
            while (nums[++i] < x);
            while (nums[--j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }

        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,2,0,0]\n
// @lcpr case=end

 */

