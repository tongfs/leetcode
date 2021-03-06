/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i ++ )
            f[i] = f[i & (i - 1)] + 1;
        return f;
    }
};
// @lc code=end

