/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, sum = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < hours.size(); i ++ ) {
            sum += hours[i] > 8 ? 1 : -1;
            if (sum > 0) res = i + 1;
            else {
                if (map.count(sum - 1)) res = max(res, i - map[sum - 1]);
                if (!map.count(sum)) map[sum] = i;
            }
        }

        return res;
    }
};
// @lc code=end

