/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int n;
    vector<string> path = {"JFK"};
    unordered_map<string, map<string ,int>> s_map;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size(); // 总共有 n 张机票
        for (auto& t: tickets) s_map[t[0]][t[1]] ++ ;

        dfs("JFK", 0);
        return path;
    }

    bool dfs(string from, int u) {
        if (u == n) return true;

        auto& t_map = s_map[from];  // 这里一定要引用
        for (auto& x: t_map) {
            if (x.second) {
                x.second -- ;
                path.push_back(x.first);
                if (dfs(x.first, u + 1)) return true;
                path.pop_back();
                x.second ++ ;
            }
        }

        return false;
    }
};
// @lc code=end

