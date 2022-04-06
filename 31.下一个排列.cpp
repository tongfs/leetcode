/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while (k > 0 && nums[k - 1] >= nums[k]) k -- ;  // 找到从哪个下边开始单调不增

        if (k) {
            int t = k;
            while (t < nums.size() && nums[t] > nums[k - 1]) t ++ ;
            swap(nums[t - 1], nums[k - 1]);
        }

        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

