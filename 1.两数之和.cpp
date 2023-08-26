/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=21910
 *
 * [1] 两数之和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(target - nums[i]))
                return {map[target - nums[i]], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

