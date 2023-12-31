/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <istream>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++ ) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j ++ ) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                    for (int k = j + 1, l = nums.size() - 1; k < l; k ++ ) {
                        if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                        while (k < l - 1 && (long long)nums[i] + nums[j] + nums[k] + nums[l - 1] >= target) l -- ;
                        if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target)
                            res.push_back({nums[i], nums[j], nums[k], nums[l]});
                }
            }
        }
        return res;
    }
};
// @lc code=end

