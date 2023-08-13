/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=21910
 *
 * [39] 组合总和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, target, candidates);
        return res;
    }

    void dfs(int u, int target, vector<int>& nums) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        if (u == nums.size()) return;

        for (int i = 0; nums[u] * i <= target; i++) {
            dfs(u + 1, target - nums[u] * i, nums);
            path.push_back(nums[u]);
        }

        for (int i = 0; nums[u] * i <= target; i++) {
            path.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

