/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=21909
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            if (mid <= x / mid)l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
