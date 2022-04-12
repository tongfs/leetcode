/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res = INT_MAX, n = triangle.size();
        for (int i = n - 2; i >= 0; i --)
            for (int j = 0; j <= i; j ++ )
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};
// @lc code=end

