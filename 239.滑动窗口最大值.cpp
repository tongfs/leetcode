/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=21910
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
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            while (q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i - k + 1 >= 0) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

