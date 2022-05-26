/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (auto c: address) {
            if (c == '.') res += "[.]";
            else res += c;
        }
        return res;
    }
};
// @lc code=end

