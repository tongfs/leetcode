/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=21910
 *
 * [56] 合并区间
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int st = intervals[0][0], ed = intervals[0][1];
        for (auto& i : intervals) {
            if (i[0] > ed) {
                res.push_back({st, ed});
                st = i[0], ed = i[1];
            } else {
                ed = max(ed, i[1]);
            }
        }
        res.push_back({st, ed});
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

