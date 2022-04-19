/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& i: prerequisites) {
            g[i[1]].push_back(i[0]);
            d[i[0]] ++ ;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++ ) if (!d[i]) q.push(i);

        vector<int> res;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);
            for (auto i: g[t]) if ( -- d[i] == 0) q.push(i);
        }

        if (res.size() < n) return {};
        return res;
    }
};
// @lc code=end

