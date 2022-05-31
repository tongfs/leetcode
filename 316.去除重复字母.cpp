/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char> set;        // 记录每个字符是否在当前答案中出现
        unordered_map<char, int> map;   // 记录每个字符在原串中出现的个数
        for (auto c: s) map[c] ++ ;

        string res;
        for (int i = 0, j = 0; s[i]; map[s[i ++ ]] -- ) {
            if (set.count(s[i])) continue;
            while (res.size() && res.back() > s[i] && map[res.back()] && !set.count(s[i])) {
                set.erase(res.back());
                res.pop_back();
            }
            res.push_back(s[i]);
            set.insert(s[i]);
        }

        return res;
    }
};
// @lc code=end

