/*
 * @lc app=leetcode.cn id=7 lang=cpp
 * @lcpr version=21910
 *
 * [7] 整数反转
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (x > 0 && res > (INT_MAX - x % 10) / 10) return 0;
            if (x < 0 && res < (INT_MIN - x % 10) / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 123\n
// @lcpr case=end

// @lcpr case=start
// -123\n
// @lcpr case=end

// @lcpr case=start
// 120\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */
