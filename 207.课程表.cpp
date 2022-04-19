/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& i: prerequisites) {
            g[i[1]].push_back(i[0]);
            d[i[0]] ++ ;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++ ) if (!d[i]) q.push(i);

        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt ++ ;
            for (auto i: g[t]) if ( -- d[i] == 0) q.push(i);
        }

        return cnt == n;
    }
};
// @lc code=end

