/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

#include "mylib.h"

// @lc code=start
class NumArray {
public:
    vector<int> sum;

    NumArray(vector<int>& nums) {
        sum = nums;
        for (int i = 1; i < sum.size(); i ++ )
            sum[i] += sum[i - 1];
    }
    
    int sumRange(int l, int r) {
        if (!l) return sum[r];
        return sum[r] - sum[l - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

