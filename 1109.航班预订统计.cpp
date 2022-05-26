/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for (auto& b: bookings) {
            int l = b[0] - 1, r = b[1] - 1, c = b[2];
            res[l] += c;
            if (r + 1 < n) res[r + 1] -= c;
        }
        for (int i = 1; i < n; i ++ ) res[i] += res[i - 1];
        return res;
    }
};
// @lc code=end

