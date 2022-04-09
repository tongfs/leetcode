/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }

    // 和第40题类似
    void dfs(int u, vector<int>& nums) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        int k = u + 1;
        while (k < nums.size() && nums[k] == nums[u]) k ++ ;

        for (int i = 0; i <= k - u; i ++ ) {
            dfs(k, nums);
            path.push_back(nums[u]);
        }

        for (int i = 0; i <= k - u; i ++ ) {
            path.pop_back();
        }
    }
};
// @lc code=end

