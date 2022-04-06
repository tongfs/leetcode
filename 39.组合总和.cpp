/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates);
        return res;
    }

    // 解法一：无序DFS
    /* void dfs(int start, int target, vector<int>& nums) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }

        if (start == nums.size()) return;

        for (int i = 0; nums[start] * i <= target; i ++ ) {
            dfs(start + 1, target - nums[start] * i, nums);
            tmp.push_back(nums[start]);
        }

        for (int i = 0; nums[start] * i <= target; i ++ ) {
            tmp.pop_back();
        }
    } */

    // 解法二：有序DFS
    void dfs(int st, int target, vector<int>& nums) {
        if (st == nums.size()) return;
        if (nums[st] > target) return;

        tmp.push_back(nums[st]);
        if (nums[st] == target) res.push_back(tmp);
        else dfs(st, target - nums[st], nums);
        tmp.pop_back();

        dfs(st + 1, target, nums);    
    }
};
// @lc code=end

