/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=21909
 *
 * [18] 四数之和
 */

#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1, l = n - 1; k < l; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    while (k < l - 1 && (long long)nums[i] + nums[j] + nums[k] + nums[l - 1] >= target) l--;
                    if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target)
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */
