/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

    // 解法一：暴搜
    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        dfs(nums, u + 1); // 不选

        path.push_back(nums[u]);
        dfs(nums, u + 1); // 选
        path.pop_back();
    }

    // 解法二：二进制
    void bit_manipulation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < 1 << n; i ++ ) {
            vector<int> t;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1) t.push_back(nums[j]);
            res.push_back(t);
        }
    }
};
// @lc code=end

