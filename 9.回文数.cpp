/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=21910
 *
 * [9] 回文数
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int t = x, res = 0;
        while (t) {
            if (res > (INT_MAX - t % 10) / 10) return false;
            res = res * 10 + t % 10;
            t /= 10;
        }
        return res == x;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

