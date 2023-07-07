/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=21909
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int f[2] = {1, 2};
        for (int i = 3; i <= n; i++) f[i - 1 & 1] += f[i & 1];
        return f[n - 1 & 1];
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
