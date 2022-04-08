/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int k = 0;
        
        // 左边没有重叠的部分
        while (k < intervals.size() && intervals[k][1] < newInterval[0])
            res.push_back(intervals[k ++ ]);

        if (k < intervals.size()) {
            newInterval[0] = min(newInterval[0], intervals[k][0]);
            while (k < intervals.size() && intervals[k][0] <= newInterval[1])
                newInterval[1] = max(newInterval[1], intervals[k ++ ][1]);
        }
        res.push_back(newInterval);

        while (k < intervals.size()) res.push_back(intervals[k ++ ]);

        return res;
    }
};
// @lc code=end

