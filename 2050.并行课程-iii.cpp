/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 * @lcpr version=21910
 *
 * [2050] 并行课程 III
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> f;
    vector<vector<int>> prev;

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        f = vector<int>(n + 1);
        prev = vector<vector<int>>(n + 1);

        for (auto& r : relations) prev[r[1]].push_back(r[0]);

        int res = 0;
        for (int i = 1; i <= n; i++) res = max(res, dfs(i, time));
        return res;
    }

    int dfs(int i, vector<int>& time) {
        if (f[i]) return f[i];
        for (auto c : prev[i]) f[i] = max(f[i], dfs(c, time));
        return f[i] = f[i] + time[i - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[1,3],[2,3]]\n[3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,5],[2,5],[3,5],[3,4],[4,5]]\n[1,2,3,4,5]\n
// @lcpr case=end

 */

