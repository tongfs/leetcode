/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=21910
 *
 * [16] 最接近的三数之和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int d = 0x3f3f3f3f, res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (abs(t - target) < d) {
                    d = abs(t - target);
                    res = t;
                }
                if (t - target > 0) k--;
                else j++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

 */

