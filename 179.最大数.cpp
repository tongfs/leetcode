/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            auto a = to_string(x), b = to_string(y);
            return a + b > b + a;
        });
        
        string res;
        for (auto x: nums) res += to_string(x);
        if (res[0] == '0') return "0";
        return res;
    }
};
// @lc code=end

