/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 * @lcpr version=21910
 *
 * [1572] 矩阵对角线元素的和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += mat[i][i];
            int j = n - i - 1;
            if (i != j) res += mat[i][j];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[5]]\n
// @lcpr case=end

 */

