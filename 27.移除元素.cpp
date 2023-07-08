/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=21909
 *
 * [27] 移除元素
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[k++] = nums[i];
        return k;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */
