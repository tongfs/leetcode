/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        return two_points(n);
    }

    // 解法一：哈希表
    bool hash(int n) {
        unordered_set<int> set;
        while (!set.count(n)) {
            if (n == 1) return true;
            set.insert(n);
            int t = 0;
            while (n) {
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
        }
        return false;
    }

    // 解法二：快慢指针
    bool two_points(int n) {
        int fast = get(n), slow = n;
        while (fast != slow)
            fast = get(get(fast)), slow = get(slow);
        if (fast == 1) return true;
        return false;
    }

    int get(int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};
// @lc code=end

