/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=21909
 *
 * [26] 删除有序数组中的重复项
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[k - 1])
                nums[k++] = nums[i];
        return k;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */
