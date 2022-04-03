/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        typedef long long LL;
        bool is_minus = dividend >= 0 ^ divisor > 0;
        vector<LL> exp; // 存放除数的幂

        LL x = abs((LL)dividend), y = abs((LL)divisor);
        for (LL i = y; i <= x; i += i) exp.push_back(i);

        LL res = 0;
        for (int i = exp.size() - 1; i >= 0; i -- ) 
            if (x - exp[i] >= 0) {
                res += 1LL << i;
                x -= exp[i];
            }

        if (is_minus) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        return res;
    }
};
// @lc code=end

