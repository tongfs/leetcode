/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=21909
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
            res = max(res, (j - i) * min(height[i], height[j]));
            if (height[i] > height[j]) j--;
            else i++;
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
