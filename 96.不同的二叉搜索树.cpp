/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=21909
 *
 * [96] 不同的二叉搜索树
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> f;
    int numTrees(int n) {
        f = vector<int>(n + 1);
        f[0] = 1;
        return dp(n);
    }

    /**
     * memoized search
     */
    int dfs(int n) {
        if (f[n]) return f[n];
        for (int i = 1; i <= n; i++)
            f[n] += dfs(i - 1) * dfs(n - i);
        return f[n];
    }

    /**
     * dp
     * f[i]: [1，i] 有多少种排列
     */
    int dp(int n) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                f[i] += f[j - 1] * f[i - j];
        return f[n];
    }

    /**
     * 卡特兰数
     */
    int catalan(int n) {
        long long res = 1;
        for (int i = 1, j = 2 * n; i <= n; i++, j--) {
            res *= j;
            res /= i;
        }
        return res / (n + 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
