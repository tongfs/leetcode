/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=21910
 *
 * [11] 盛最多水的容器
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

