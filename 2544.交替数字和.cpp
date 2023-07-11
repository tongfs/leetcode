/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 * @lcpr version=21909
 *
 * [2544] 交替数字和
 */

// @lc code=start
class Solution {
public:
    int alternateDigitSum(int n) {
        int len = 0, res = 0, sign = 1;
        for (int sign = 1; n; n /= 10, len++, sign = -sign)
            res += n % 10 * sign;

        if ((len & 1) == 0) return -res;
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 521\n
// @lcpr case=end

// @lcpr case=start
// 111\n
// @lcpr case=end

// @lcpr case=start
// 886996\n
// @lcpr case=end

 */
