/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=21909
 *
 * [33] 搜索旋转排序数组
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int t = nums[0];
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= t) l = mid;
            else r = mid - 1;
        }

        if (target < t) l++, r = nums.size() - 1;
        else l = 0;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[r] != target) return -1;
        return l;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
