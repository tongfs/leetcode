/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1, map2;
        for (int i = 0; i < s.size(); i ++ ) {
            if (!map1.count(s[i]) && !map2.count(t[i]))
                map1[s[i]] = t[i], map2[t[i]] = s[i];
            else if (map1.count(s[i]) && map1[s[i]] == t[i])
                continue;
            else return false;
        }
        return true;
    }
};
// @lc code=end

