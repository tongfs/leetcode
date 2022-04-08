/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0, tmp = 0; i < nums.size(); i ++ ) {
            tmp += nums[i];
            res = max(res, tmp);
            tmp = max(tmp, 0);
        }
        return res;
    }
};
// @lc code=end

