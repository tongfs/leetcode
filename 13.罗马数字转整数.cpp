/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> h;
        h['I'] = 1, h['V'] = 5;
        h['X'] = 10, h['L'] = 50;
        h['C'] = 100, h['D'] = 500;
        h['M'] = 1000;

        int res = 0;
        for (int i = 0; i < s.size() - 1; i ++ ) {
            if (h[s[i]] < h[s[i + 1]]) res -= h[s[i]];
            else res += h[s[i]];
        }
        res += h[s[s.size() - 1]];

        return res;
    }
};
// @lc code=end

