/*
 * @lc app=leetcode.cn id=2679 lang=cpp
 * @lcpr version=21909
 *
 * [2679] 矩阵中的和
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        return method2(nums); 
    }

    /**
     * sort
     */
    int method1(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        for (int i = 0; i < n; i++)
            sort(nums[i].begin(), nums[i].end());

        int res = 0;
        for (int j = 0; j < m; j++) {
            int max_v = 0;
            for (int i = 0; i < n; i++)
                max_v = max(max_v, nums[i][j]);
            res += max_v;
        }

        return res;
    }

    /**
     * heap
     */
    int method2(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<priority_queue<int>> heaps(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heaps[i].push(nums[i][j]);
            }
        }

        int res = 0;
        for (int j = 0; j < m; j++) {
            int max_v = 0;
            for (int i = 0; i < n; i++) {
                max_v = max(max_v, heaps[i].top());
                heaps[i].pop();
            }
            res += max_v;
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
