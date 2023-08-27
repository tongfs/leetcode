/*
 * @lc app=leetcode.cn id=228 lang=cpp
 * @lcpr version=21910
 *
 * [228] 汇总区间
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            while (j + 1 < nums.size() && nums[j] + 1 == nums[j + 1]) j++;
            string tmp = to_string(nums[i]);
            if (i != j) tmp += "->" + to_string(nums[j]);
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,4,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,4,6,8,9]\n
// @lcpr case=end

 */

