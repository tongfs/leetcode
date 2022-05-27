/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

bool isBadVersion(int version);

// @lc code=start
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

