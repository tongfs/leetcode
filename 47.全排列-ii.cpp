/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    typedef pair<int, int> PII;

    vector<bool> st;
    vector<int> path;
    vector<PII> seq;
    vector<vector<int>> res;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // return method1(nums);
        return method2(nums);
    }

    // 方法一：记录下来每个数出现了几次
    vector<vector<int>> method1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; j < nums.size(); i ++ ) {
            while (j < nums.size() && nums[i] == nums[j]) j ++ ;
            seq.push_back({nums[i], j - i});
            i = j - 1;
        }
        dfs1(0, nums);
        return res;
    }

    // 方法二：判断前后两个数是否一样
    vector<vector<int>> method2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        st = vector<bool>(nums.size());
        path = vector<int>(nums.size());
        dfs2(0, nums);
        return res;
    }

    void dfs1(int u, vector<int>& nums) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < seq.size(); i ++ ) {
            if (seq[i].second) {
                seq[i].second -- ;
                path.push_back(seq[i].first);
                dfs1(u + 1, nums);
                path.pop_back();
                seq[i].second ++ ;
            }
        }
    }

    void dfs2(int u, vector<int>& nums) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++ ) {
            if (!st[i]) {
                if (i && nums[i] == nums[i - 1] && !st[i - 1]) continue;
                st[i] = true;
                path[u] = nums[i];
                st[i] = false;
                dfs2(u + 1, nums);
            }
        }
    }
};
// @lc code=end

