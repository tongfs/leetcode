/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        typedef long double LD;

        int res = 0;

        for (int i = 0; i < points.size(); i ++ ) {
            int vl = 0, cl = 0;
            unordered_map<LD, int> map;
            for (int j = i; j < points.size(); j ++ ) {
                if (points[i] == points[j]) cl ++ ;
                else if (points[i][0] == points[j][0]) vl ++ ;
                else {
                    LD k = (LD)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    map[k] ++ ;
                }
            }

            int maxt = vl;
            for (auto& [k, t]: map) maxt = max(maxt, t);
            res = max(res, maxt + cl);
        }

        return res;
    }
};
// @lc code=end

