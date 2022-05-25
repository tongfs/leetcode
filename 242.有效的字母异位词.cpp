/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> a, b;
        for (auto c: s) a[c] ++ ;
        for (auto c: t) b[c] ++ ;
        return a == b;
    }
};
// @lc code=end

