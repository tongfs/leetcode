/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> combine(int _n, int k) {
        n = _n;
        dfs(1, k);
        return res;
    }

    void dfs(int u, int k) {
        if (!k) {
            res.push_back(path);
            return;
        }

        for (int i = u; i <= n; i ++ ) {
            path.push_back(i);
            dfs(i + 1, k - 1);
            path.pop_back();
        }
    }
};
// @lc code=end

