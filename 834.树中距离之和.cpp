/*
 * @lc app=leetcode.cn id=834 lang=cpp
 * @lcpr version=21909
 *
 * [834] 树中距离之和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int n;
    vector<int> cnt, res;
    vector<vector<int>> g;

    vector<int> sumOfDistancesInTree(int _n, vector<vector<int>>& edges) {
        n = _n;
        cnt.resize(n, 1);
        res.resize(n);
        g.resize(n);

        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return res;
    }

    void dfs1(int u, int p) {
        for (auto x : g[u]) {
            if (x != p) {
                dfs1(x, u);
                cnt[u] += cnt[x];
                res[u] += res[x] + cnt[x];
            }
        }
    }

    void dfs2(int u, int p) {
        for (auto x : g[u]) {
            if (x != p) {
                res[x] = res[u] + (n - cnt[x]) - cnt[x];
                dfs2(x, u);
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

 */
