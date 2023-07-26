/*
 * @lc app=leetcode.cn id=2679 lang=cpp
 * @lcpr version=21910
 *
 * [2679] 矩阵中的和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        for (auto& arr : nums) sort(arr.begin(), arr.end());
        for (int i = 0; i < nums[0].size(); i++) {
            int t = INT_MIN;
            for (int j = 0; j < nums.size(); j++) t = max(t, nums[j][i]);
            res += t;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */

