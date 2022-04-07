/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stk;

        for (int i = 0; i < height.size(); i ++ ) {
            while (stk.size() && height[stk.top()] < height[i]) {
                int h = height[stk.top()];    // 记录底部的高度
                stk.pop();
                if (stk.size()) {
                    res += (min(height[stk.top()], height[i]) - h) * (i - stk.top() - 1);
                }
            }
            stk.push(i);
        }

        return res;
    }
};
// @lc code=end

