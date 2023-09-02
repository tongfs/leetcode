/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=21910
 *
 * [560] 和为 K 的子数组
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];
        unordered_map<int, int> map;
        map[0] = 1;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += map[sum[i] - k];
            map[sum[i]]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */

