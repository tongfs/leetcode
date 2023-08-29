/*
 * @lc app=leetcode.cn id=剑指 Offer 04 lang=cpp
 * @lcpr version=21910
 *
 * [剑指 Offer 04] 二维数组中的查找
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0, j = m - 1; i < n && j >= 0; ) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};
// @lc code=end



