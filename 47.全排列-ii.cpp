/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=21910
 *
 * [47] 全排列 II
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        st = vector<bool>(n);
        dfs(0, nums);
        return res;
    }

    void dfs(int u, vector<int>& nums) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                if (i && nums[i] == nums[i - 1] && !st[i - 1]) continue;
                st[i] = true;
                path.push_back(nums[i]);
                dfs(u + 1, nums);
                path.pop_back();
                st[i] = false;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

