/*
 * @lc app=leetcode.cn id=1125 lang=cpp
 *
 * [1125] 最小的必要团队
 */

#include "mylib.h"

// @lc code=start
class Solution {
   public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        vector<int> f(1 << n, n + 1), g(m);
        unordered_map<string, int> map;

        for (int i = 0; i < n; i ++ ) map[req_skills[i]] = i;
        for (int i = 0; i < m; i ++ )
            for (auto& skill: people[i])
                g[i] |= 1 << map[skill];

        vector<pair<int, int>> path(1 << n);
        f[0] = 0;
        for (int i = 0; i < 1 << n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                int& t = f[i | g[j]];
                if (t > f[i] + 1) {
                    path[i | g[j]] = {i, j};
                    t = f[i] + 1;
                }
            }

        vector<int> res;
        for (int i = (1 << n) - 1; i; i = path[i].first)
            res.push_back(path[i].second);
        return res;
    }
};
// @lc code=end
