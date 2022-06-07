/*
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    /* 
     * 只有三种可能：
     *      1. 连续4步产生交点
     *      2. 连续5步产生交点
     *      3. 连续6步产生交点
     */
    bool isSelfCrossing(vector<int>& dist) {
        int n = dist.size();
        if (n <= 3) return false;
        for (int i = 3; i < n; i ++ ) {
            if (dist[i] >= dist[i - 2] && dist[i - 3] >= dist[i - 1]) return true;
            if (i >= 4 && dist[i - 1] == dist[i - 3] && dist[i - 4] + dist[i] >= dist[i - 2]) return true;
            if (i >= 5 && dist[i - 2] > dist[i - 4] && dist[i] + dist[i - 4] >= dist[i - 2] && 
                dist[i - 3] > dist[i - 5] && dist[i - 3] > dist[i - 1] && dist[i - 1] + dist[i - 5] >= dist[i - 3])
                return true;
        }
        return false;
    }
};
// @lc code=end

