/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        while (n -- ) {
            int t = a;
            a = b;
            b += t;
        }
        return b;
    }
};
// @lc code=end

