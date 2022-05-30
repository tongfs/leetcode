/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> g;
    vector<int> d1, d2, p1, up;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g.resize(n);
        d1 = d2 = p1 = up = vector<int>(n);

        for (auto& e: edges) {
            auto a = e[0], b = e[1];
            g[a].push_back(b), g[b].push_back(a);
        }

        dfs_d(0, -1);
        dfs_u(0, -1);

        int Min = n - 1;
        for (int i = 0; i < n; i ++ ) Min = min(Min, max(d1[i], up[i]));
        vector<int> res;
        for (int i = 0; i < n; i ++ )
            if (max(d1[i], up[i]) == Min)
                res.push_back(i);
        return res;
    }

    // 向下遍历，记录每个节点在作为子树根节点时的最大高度
    void dfs_d(int u, int pre) {
        for (int t: g[u]) {
            if (t == pre) continue;
            dfs_d(t, u);
            int d = d1[t] + 1;
            if (d > d1[u]) {
                d2[u] = d1[u], d1[u] = d;
                p1[u] = t;
            } else if (d > d2[u]) {
                d2[u] = d;
            }
        }
    }

    // 向上遍历，补全每个点作为总根节点时的最大高度
    // 差距就在于需要统计从父节点传递过来的子树分支
    void dfs_u(int u, int pre) {
        for (int t: g[u]) {
            if (t == pre) continue;
            if (t == p1[u]) up[t] = max(up[u], d2[u]) + 1;
            else up[t] = max(up[u], d1[u]) + 1;
            dfs_u(t, u);
        }
    }
};
// @lc code=end

