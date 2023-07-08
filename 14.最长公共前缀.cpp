/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=21909
 *
 * [14] 最长公共前缀
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
                if (i == strs[j].size() || strs[j][i] != c)
                    return res;
            res += c;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
