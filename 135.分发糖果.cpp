/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> r;
    vector<int> f;

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        r = ratings;
        f = vector<int>(n);

        int res = 0;
        for (int i = 0; i < n; i ++ ) res += dfs(i);

        return res;
    }

    int dfs(int u) {
        if (f[u]) return f[u];

        f[u] = 1;
        if (u - 1 >= 0 && r[u - 1] < r[u]) f[u] = dfs(u - 1) + 1;
        if (u + 1 < r.size() && r[u + 1] < r[u]) f[u] = max(f[u], dfs(u + 1) + 1);

        return f[u];
    }
};
// @lc code=end

