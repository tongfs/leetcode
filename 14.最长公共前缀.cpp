/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=21910
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
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[0][i] != strs[j][i]) {
                    return res;
                }
            }
            res += strs[0][i];
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

