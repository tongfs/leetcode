/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> h;
        for (int i = 0; i < n; i ++ )
        {
            int t = target - nums[i];
            if (h.count(t)) return {i, h[t]};
            h[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

