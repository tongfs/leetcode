/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (matrix[mid / m][mid % m] >= target) r = mid;
            else l = mid + 1;
        }

        return matrix[l / m][l % m] == target;
    }
};
// @lc code=end

