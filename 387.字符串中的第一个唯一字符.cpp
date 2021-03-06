/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int map[26] = {0};
        for (auto c: s) map[c - 'a'] ++ ;
        for (int i = 0; i < s.size(); i ++ )
            if (map[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
// @lc code=end

