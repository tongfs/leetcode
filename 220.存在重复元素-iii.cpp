/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        typedef long long LL;
        
        multiset<LL> set;
        set.insert(-1e18), set.insert(1e18);

        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            if (i - j > k) set.erase(set.find(nums[j ++ ]));
            auto it = set.lower_bound(nums[i]);
            if (abs(*it - nums[i]) <= t) return true;
            it -- ;
            if (abs(*it - nums[i]) <= t) return true;
            set.insert(nums[i]);
        }

        return false;
    }
};
// @lc code=end

