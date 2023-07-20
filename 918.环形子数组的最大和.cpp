/*
 * @lc app=leetcode.cn id=918 lang=cpp
 * @lcpr version=21910
 *
 * [918] 环形子数组的最大和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n * 2 + 1, 0);

        for (int i = 1; i <= n * 2; i++)
            s[i] = s[i - 1] + nums[(i - 1) % n];
        
        deque<int> q;
        q.push_back(0);

        int res = INT_MIN;
        for (int i = 1; i <= n * 2; i++) {
            if (q.size() && i - q.front() > n) q.pop_front();
            res = max(res, s[i] - s[q.front()]);
            while (q.size() && s[q.back()] >= s[i]) q.pop_back();
            q.push_back(i);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-2,3,-2]\n
// @lcpr case=end

// @lcpr case=start
// [5,-3,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,-2,2,-3]\n
// @lcpr case=end

 */

