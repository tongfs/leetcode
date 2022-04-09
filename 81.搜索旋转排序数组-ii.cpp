/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r && nums[l] == nums[r]) l ++ ;

        int t = l;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[t]) l = mid;
            else r = mid - 1;
        }

        if (target >= nums[t]) l = t;
        else l ++ , r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return nums[r] == target;
    }
};
// @lc code=end

