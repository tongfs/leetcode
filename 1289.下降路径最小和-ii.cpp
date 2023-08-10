/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 * @lcpr version=21910
 *
 * [1289] 下降路径最小和  II
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int min_sum1 = 0, idx = -1;
        int min_sum2 = 0;

        for (int i = 0; i < n; i++) {
            int cur_min_sum1 = INT_MAX, cur_idx = -1;
            int cur_min_sum2 = INT_MAX;
            for (int j = 0; j < n; j++) {
                int cur_sum = (j == idx ? min_sum2 : min_sum1) + grid[i][j];
                if (cur_sum < cur_min_sum1) {
                    cur_min_sum2 = cur_min_sum1;
                    cur_min_sum1 = cur_sum;
                    cur_idx = j;
                } else if (cur_sum < cur_min_sum2) {
                    cur_min_sum2 = cur_sum;
                }
            }
            min_sum1 = cur_min_sum1;
            min_sum2 = cur_min_sum2;
            idx = cur_idx;
        }

        return min_sum1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[7]]\n
// @lcpr case=end

 */

