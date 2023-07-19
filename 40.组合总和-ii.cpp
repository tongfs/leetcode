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
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& nums, int target, int start) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        if (start == nums.size()) return;

        int len = 1;
        while (start + len < nums.size() && nums[start] == nums[start + len]) len++;
        
        for (int i = 0; nums[start] * i <= target && i <= len; i++) {
            dfs(nums, target - nums[start] * i, start + len);
            path.push_back(nums[start]);
        }

        for (int i = 0; nums[start] * i <= target && i <= len; i++)
            path.pop_back();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */
