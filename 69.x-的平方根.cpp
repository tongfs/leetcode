/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = r - (r - l >> 1);
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
// @lc code=end

