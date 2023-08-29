/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=21910
 *
 * [54] 螺旋矩阵
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int d = 0;
        int n = matrix.size(), m = matrix[0].size();

        vector<int> res;
        vector<vector<bool>> st(n, vector<bool>(m));
        for (int i = 0, x = 0, y = 0; i < n * m; i++) {
            st[x][y] = true;
            res.push_back(matrix[x][y]);
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
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
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

