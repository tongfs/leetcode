/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        typedef pair<int, int> PII;
        const int INF = 0x3f3f3f3f;

        vector<vector<PII>> g(n);
        for (auto e: redEdges) g[e[0]].push_back({e[1], 0});
        for (auto e: blueEdges) g[e[0]].push_back({e[1], 1});

        vector<vector<int>> dist(n, vector<int>(2, INF));
        dist[0][0] = dist[0][1] = 0;
        queue<PII> q;
        q.push({0, 0}), q.push({0, 1});

        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (auto e: g[t.first]) {
                if (e.second != t.second && dist[e.first][e.second] > dist[t.first][t.second] + 1) {
                    dist[e.first][e.second] = dist[t.first][t.second] + 1;
                    q.push(e);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i ++ ) {
            int t = min(dist[i][0], dist[i][1]);
            if (t == INF) t = -1;
            res.push_back(t);
        }
        return res;
    }
};
// @lc code=end

