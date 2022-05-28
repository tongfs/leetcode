/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        for (int i = 0; i < s.size(); i ++ ) {
            int j = i;
            while (j < s.size() && s[j] != ' ') j ++ ;
            words.push_back(s.substr(i, j - i));
            i = j;
        }

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> map1;
        unordered_map<string, char> map2;

        for (int i = 0; i < pattern.size(); i ++ ) {
            auto c = pattern[i];
            auto str = words[i];
            if (!map1.count(c) && !map2.count(str))
                map1[c] = str, map2[str] = c;
            else if (map1[c] != str || map2[str] != c)
                return false;
        }

        return true;
    }
};
// @lc code=end

