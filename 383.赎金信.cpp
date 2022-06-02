/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26] = {0};
        for (auto c: magazine) map[c - 'a'] ++ ;
        for (auto c: ransomNote)
            if (!map[c - 'a'] -- )
                return false;
        return true;
    }
};
// @lc code=end

