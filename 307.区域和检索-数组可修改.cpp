/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

#include "mylib.h"

// @lc code=start
class NumArray {
public:
    int n;
    vector<int> nums, tr;

    NumArray(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        tr.resize(n + 1);
        for (int i = 1; i <= n; i ++ ) add(i, nums[i - 1]);
    }
    
    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }

    int lowbit(int x) {
        return x & -x;
    }

    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

