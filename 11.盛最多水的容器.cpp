/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            res = max(res, (j - i) * min(height[i], height[j]));
            if (height[i] > height[j]) j -- ;
            else i ++ ;
        }
        return res;
    }
};
// @lc code=end

