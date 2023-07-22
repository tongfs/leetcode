/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=21910
 *
 * [42] 接雨水
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, height[0]), right(n, height[n - 1]);
        for (int i = 1; i < n; i++) left[i] = max(left[i - 1], height[i]);
        for (int i = n - 2; ~i; i--) right[i] = max(right[i + 1], height[i]);
        int res = 0;
        for (int i = 0; i < n; i++) res += min(left[i], right[i]) - height[i];
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
