/*
 * @lc app=leetcode.cn id=179 lang=cpp
 * @lcpr version=21910
 *
 * [179] 最大数
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            unsigned long long a = 10, b = 10;
            while (a <= x) a *= 10;
            while (b <= y) b *= 10;
            return x * b + y > y * a + x;
        });
        if (nums[0] == 0) return "0";
        string res;
        for (auto x : nums) res += to_string(x);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,30,34,5,9]\n
// @lcpr case=end

 */

