/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        
        int st = intervals[0][0], ed = intervals[0][1];
        for (auto& in : intervals) {
            if (in[0] > ed) {
                res.push_back({st, ed});
                st = in[0];
                ed = in[1];
            } else {
                ed = max(ed, in[1]);
            }
        }
        res.push_back({st, ed});

        return res;
    }
};
// @lc code=end

