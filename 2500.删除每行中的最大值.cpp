/*
 * @lc app=leetcode.cn id=2500 lang=cpp
 * @lcpr version=21910
 *
 * [2500] 删除每行中的最大值
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;
        for (auto& arr : grid) sort(arr.begin(), arr.end());
        for (int j = 0; j < grid[0].size(); j++) {
            int t = 0;
            for (int i = 0; i < grid.size(); i++) t = max(t, grid[i][j]);
            res += t;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,4],[3,3,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[10]]\n
// @lcpr case=end

 */

