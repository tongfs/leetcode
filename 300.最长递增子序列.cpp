/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=21910
 *
 * [300] 最长递增子序列
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    f[i] = max(f[i], f[j] + 1);

        int res = 1;
        for (auto x : f) res = max(res, x);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

