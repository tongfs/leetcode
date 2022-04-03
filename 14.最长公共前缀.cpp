/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        for (int i = 0; ; i ++ ) {
            if (strs[0].size() <= i) return res;
            char c = strs[0][i];
            for (auto& str : strs)
                if (str.size() <= i || str[i] != c)
                    return res;
            res += c;
        }
    }
};
// @lc code=end

