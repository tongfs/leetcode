/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 * @lcpr version=21910
 *
 * [2208] 将数组和减半的最少操作次数
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        priority_queue<double> heap;
        for (auto x : nums) heap.push(x), sum += x;

        int cnt = 0;
        for (double cur = 0; cur * 2 < sum; cnt++) {
            auto t = heap.top();
            heap.pop();
            cur += t / 2;
            heap.push(t / 2);
        }

        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,19,8,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,8,20]\n
// @lcpr case=end

 */

