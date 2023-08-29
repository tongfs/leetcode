/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=21910
 *
 * [46] 全排列
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        st.resize(nums.size());
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
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

