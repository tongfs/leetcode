/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        return method1_dp(n);
    }

    int method1_dp(int n) {
        // f[i]: 和为 n 的完全平方数的最少数量
        // f[i] = min(f[i - j * j] + 1)
        vector<int> f(n + 1, n);
        f[0] = 0;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= i / j; j ++ )
                f[i] = min(f[i], f[i - j * j] + 1);
        return f[n];
    }

    int method2_math(int n) {
        if (check(n)) return 1;

        for (int i = 1; i <= n / i; i ++ )
            if (check(n - i * i))
                return 2;

        while (n % 4 == 0) n /= 4;
        if (n % 8 != 7) return 3;
        
        return 4;
    }

    bool check(int x) {
        int r = sqrt(x);
        return r * r == x;
    }
};
// @lc code=end

