/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int q[] = {INT_MAX, INT_MAX};
        for (auto x: nums) {
            int k = 2;
            while (k && q[k - 1] >= x) k -- ;
            if (k == 2) return true;
            q[k] = x;
        }
        return false;
    }
};
// @lc code=end

