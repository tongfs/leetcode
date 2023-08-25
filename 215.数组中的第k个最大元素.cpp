/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=21910
 *
 * [215] 数组中的第K个最大元素
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k);
    }

    int quick_sort(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];

        int i = l - 1, j = r + 1, x = nums[l + r >> 1];
        while (i < j) {
            while (nums[++i] > x);
            while (nums[--j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }

        if (j + 1 >= k) return quick_sort(nums, l, j, k);
        return quick_sort(nums, j + 1, r, k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

