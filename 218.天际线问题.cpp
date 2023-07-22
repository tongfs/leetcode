/*
 * @lc app=leetcode.cn id=218 lang=cpp
 * @lcpr version=21910
 *
 * [218] 天际线问题
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> points;
        multiset<int> heights;

        for (auto& b : buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        sort(points.begin(), points.end());

        heights.insert(0);
        for (auto& p : points) {
            int x = p.first, h = abs(p.second);
            if (p.second < 0) {
                if (h > *heights.rbegin())
                    res.push_back({x, h});
                heights.insert(h);
            } else {
                heights.erase(heights.find(h));
                if (h > *heights.rbegin())
                    res.push_back({x, *heights.rbegin()});
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2,3],[2,5,3]]\n
// @lcpr case=end

 */
