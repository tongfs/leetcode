/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=21909
 *
 * [16] 最接近的三数之和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int d = 0x3f3f3f3f, res, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k] - target;
                if (d > abs(t)) {
                    d = abs(t);
                    res = nums[i] + nums[j] + nums[k];
                }
                if (t < 0) j++;
                else k--;
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
