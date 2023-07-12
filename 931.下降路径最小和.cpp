/*
 * @lc app=leetcode.cn id=931 lang=cpp
 * @lcpr version=21909
 *
 * [931] 下降路径最小和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int t = matrix[i - 1][j];
                if (j) t = min(t, matrix[i - 1][j - 1]);
                if (j < n - 1) t = min(t, matrix[i - 1][j + 1]);
                matrix[i][j] += t;
            }
        }

        int res = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) res = min(res, matrix[n - 1][i]);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,3],[6,5,4],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[-19,57],[-40,-5]]\n
// @lcpr case=end

 */
