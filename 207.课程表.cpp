/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=21910
 *
 * [207] 课程表
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> d(n);
        vector<vector<int>> g(n);

        for (auto& pre : prerequisites) {
            d[pre[0]]++;
            g[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) if (!d[i]) q.push(i);

        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt++;
            for (auto i : g[t]) if (--d[i] == 0) q.push(i);
        }

        return cnt == n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

