/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /* sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i ++ ) {
            if (i && candidates[i] == candidates[i - 1]) continue;
            dfs(i, target, candidates);
        }
        return res; */

        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates);
        return res;
    }

    // 解法一：
    /* void dfs(int st, int target, vector<int>& nums) {
        if (nums[st] > target) return;

        tmp.push_back(nums[st]);
        if (nums[st] == target) res.push_back(tmp);
        else {
            for (int i = st + 1; i < nums.size() ; i ++ ) {
                if (i > st + 1 && nums[i] == nums[i - 1]) continue;
                dfs(i, target - nums[st], nums);
            }
        }
        tmp.pop_back();
    } */

    // 解法二：按照出现的次数，这样写的好处是可以和上一题思路相同
    void dfs(int st, int target, vector<int>& nums) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        if (st == nums.size()) return;

        int k = st + 1;
        while (k < nums.size() && nums[k] == nums[st]) k ++ ;

        for (int i = 0; i <= k - st && nums[st] * i <= target; i ++ ) {
            dfs(k, target - nums[st] * i, nums);
            tmp.push_back(nums[st]);
        }

        for (int i = 0; i <= k - st && nums[st] * i <= target; i ++ ) {
            tmp.pop_back();
        }
    }
};
// @lc code=end

