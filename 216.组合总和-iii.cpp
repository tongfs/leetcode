/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int k, n;
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum3(int _k, int _n) {
        k = _k, n = _n;
        dfs(0, 1, 0);
        return res;
    }

    void dfs(int u, int p, int sum) {
        if (u == k) {
            if (sum == n) res.push_back(path);
            return;
        }

        for (int i = p; i < 10; i ++ ) {
            if (sum + i > n) break;
            path.push_back(i);
            dfs(u + 1, i + 1, sum + i);
            path.pop_back();
        }
    }
};
// @lc code=end

