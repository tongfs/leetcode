/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        if (m >= 0) return qpow(x, m);
        else return 1 / qpow(x, -m);
    }

    double qpow(double x, long long n) {
        double res = 1;
        while (n) {
            if (n & 1) res *= x;
            n >>= 1;
            x *= x;
        }
        return res;
    }
};
// @lc code=end

