/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=21910
 *
 * [40] 组合总和 II
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates);
        return res;
    }

    void dfs(int u, int target, vector<int>& nums) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        if (u == nums.size()) return;

        int len = 1;
        while (u + len < nums.size() && nums[u] == nums[u + len]) len++;

        for (int i = 0; i <= len && nums[u] * i <= target; i++) {
            dfs(u + len, target - nums[u] * i, nums);
            path.push_back(nums[u]);
        }

        for (int i = 0; i <= len && nums[u] * i <= target; i++) {
            path.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8,\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5,\n
// @lcpr case=end

 */

