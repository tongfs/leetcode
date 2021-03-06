/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        st = vector<bool>(nums.size());
        dfs(0, nums);
        return res;
    }

    void dfs(int u, vector<int>& nums) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++ ) {
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

