/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto& str : strs) {
            auto s = str;
            sort(s.begin(), s.end());
            map[s].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& item : map) res.push_back(item.second);
        return res;
    }
};
// @lc code=end

