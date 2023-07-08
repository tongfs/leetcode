/*
 * @lc app=leetcode.cn id=29 lang=cpp
 * @lcpr version=21909
 *
 * [29] 两数相除
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        typedef long long LL;
        vector<LL> exp; // 存放除数的幂
        bool is_minus = dividend >= 0 ^ divisor > 0;

        LL x = abs((LL)dividend), y = abs((LL)divisor);
        for (LL i = y; i <= x; i <<= 1) exp.push_back(i);

        LL res = 0;
        for (int i = exp.size() - 1; i >= 0; i--) {
            if (x - exp[i] >= 0) {
                res += 1LL << i;
                x -= exp[i];
            }
        }

        if (is_minus) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n3\n
// @lcpr case=end

// @lcpr case=start
// 7\n-3\n
// @lcpr case=end

 */

