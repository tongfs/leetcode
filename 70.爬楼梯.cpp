/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=21910
 *
 * [70] 爬楼梯
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            int t = a + b;
            a = b, b = t;
        }
        return b;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

