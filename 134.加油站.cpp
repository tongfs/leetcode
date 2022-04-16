/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int k = 0, r = 0, total = 0;
        for (int i = 0; i < gas.size(); i ++ ) {
            total += gas[i] - cost[i];
            r += gas[i] - cost[i];
            if (r < 0) r = 0, k = i + 1;
        }
        if (total >= 0) return k;
        return -1;
    }
};
// @lc code=end

