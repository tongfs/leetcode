/*
 * @lc app=leetcode.cn id=1499 lang=cpp
 * @lcpr version=21910
 *
 * [1499] 满足不等式的最大值
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        using PII = pair<int, int>;
        deque<PII> q;

        int res = INT_MIN;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            while (q.size() && x - q.front().second > k) q.pop_front();
            if (q.size()) res = max(res, x + y + q.front().first);
            while (q.size() && y - x >= q.back().first) q.pop_back();
            q.push_back({y - x, x});
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,0],[5,10],[6,-10]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[3,0],[9,2]]\n3\n
// @lcpr case=end

 */
