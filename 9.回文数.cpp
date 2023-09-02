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
        int y = 0, t = x;
        while (t) {
            if (y >= (INT_MAX - t % 10) / 10) return false;
            y = y * 10 + t % 10;
            t /= 10;
        }
        return x == y;
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

