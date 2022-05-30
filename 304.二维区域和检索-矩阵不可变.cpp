/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

#include "mylib.h"

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> sum;

    NumMatrix(vector<vector<int>>& matrix) {
        sum = matrix;
        int n = sum.size(), m = sum[0].size();
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!i && !j) continue;
                else if (!i) sum[i][j] += sum[i][j - 1];
                else if (!j) sum[i][j] += sum[i - 1][j];
                else sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        if (!x1 && !y1) return sum[x2][y2];
        else if (!x1) return sum[x2][y2] - sum[x2][y1 - 1];
        else if (!y1) return sum[x2][y2] - sum[x1 - 1][y2];
        else return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

