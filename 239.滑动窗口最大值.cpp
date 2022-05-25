/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++ ) {
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i - k + 1 >= 0) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end

