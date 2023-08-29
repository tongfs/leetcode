/*
 * @lc app=leetcode.cn id=57 lang=cpp
 * @lcpr version=21910
 *
 * [57] 插入区间
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int k = 0, n = intervals.size();

        while (k < n && intervals[k][1] < newInterval[0])
            res.push_back(intervals[k++]);
        
        if (k < n) {
            newInterval[0] = min(newInterval[0], intervals[k][0]);
            while (k < n && intervals[k][0] <= newInterval[1])
                newInterval[1] = max(newInterval[1], intervals[k++][1]);
        }
        res.push_back(newInterval);

        while (k < n) res.push_back(intervals[k++]);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[6,9]]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
// @lcpr case=end

// @lcpr case=start
// []\n[5,7]\n
// @lcpr case=end

// @lcpr case=start
// [[1,5]]\n[2,3]\n
// @lcpr case=end

// @lcpr case=start
// [[1,5]]\n[2,7]\n
// @lcpr case=end

 */

