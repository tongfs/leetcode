/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=21910
 *
 * [78] 子集
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }

    void dfs(int u, vector<int>& nums) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        dfs(u + 1, nums);
        path.push_back(nums[u]);
        dfs(u + 1, nums);
        path.pop_back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

