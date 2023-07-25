/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * @lcpr version=21910
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;

        int res = 1;
        while (n >= 5) n -= 3, res *= 3;
        return res * n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

