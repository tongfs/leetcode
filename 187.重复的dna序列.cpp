/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> map;

        for (int i = 0; i + 9 < s.size(); i ++ ) map[s.substr(i, 10)] ++ ;
        for (auto& [t, k]: map) if (k > 1) res.push_back(t);

        return res;
    }
};
// @lc code=end

