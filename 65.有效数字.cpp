/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        // 去掉前后空格
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == ' ') l ++ ;
        while (l <= r && s[r] == ' ') r -- ;
        if (l > r) return false;
        s = s.substr(l, r - l + 1);

        // 如果开头有正负号，则去掉
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);

        // 如果是空串，则无效
        if (s.empty()) return false;

        // 如果小数点前后没有数字，则无效
        if (s[0] == '.' && (s.size() == 1 || s[1] == 'e' || s[1] == 'E')) return false;

        bool dot = false, e = false;    // 记录小数点和e是否出现
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == '.') {
                if (dot || e) return false;
                dot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!i || i == s.size() - 1 || e) return false;
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 1 == s.size() - 1) return false;
                    i ++ ;
                }
                e = true;
            } else if (!isdigit(s[i])) return false;
        }

        return true;
    }
};
// @lc code=end

