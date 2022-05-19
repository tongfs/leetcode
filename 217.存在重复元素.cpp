/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto x: nums) if (map[x] ++ == 1) return true;
        return false;
    }
};
// @lc code=end

