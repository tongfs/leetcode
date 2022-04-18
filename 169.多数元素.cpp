/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i ++ )
            if (!cnt) res = nums[i], cnt = 1;
            else if (nums[i] == res) cnt ++ ;
            else cnt -- ;
        return res;
    }
};
// @lc code=end

