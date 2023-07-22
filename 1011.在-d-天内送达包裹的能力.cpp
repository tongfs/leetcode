/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 * @lcpr version=21910
 *
 * [1011] 在 D 天内送达包裹的能力
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_w = 0, sum = 0, n = weights.size();
        for (auto w : weights) max_w = max(max_w, w), sum += w;
        int l = max_w, r = sum;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(weights, mid, days)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    bool check(vector<int>& weights, int load, int days) {
        int tot_days = 1, day_load = 0;
        for (auto w : weights) {
            if (day_load + w > load) {
                if (++tot_days > days) return false;
                day_load = w;
            } else {
                day_load += w;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,4,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,1]\n4\n
// @lcpr case=end

 */

