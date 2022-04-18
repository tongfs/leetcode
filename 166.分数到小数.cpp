/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        typedef long long LL;

        LL a = numerator, b = denominator;
        if (a % b == 0) return to_string(a / b);

        string res;
        unordered_map<LL, int> map;

        if (numerator < 0 ^ denominator < 0) res += '-';
        a = abs(a), b = abs(b);
        res += to_string(a / b) + '.';
        a %= b;

        while (a) {
            map[a] = res.size();
            a *= 10;
            res += to_string(a / b);
            a %= b;
            if (map.count(a)) {
                res = res.substr(0, map[a]) + '(' + res.substr(map[a]) + ')';
                break;
            }
        }

        return res;
    }
};
// @lc code=end

