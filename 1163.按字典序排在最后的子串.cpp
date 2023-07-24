/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 * @lcpr version=21910
 *
 * [1163] 按字典序排在最后的子串
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, n = s.size();
        while (j < n) {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) k++;
            if (j + k < n && s[i + k] < s[j + k]) {
                i += k + 1;
                j = max(j, i + 1);
            } else {
                j += k + 1;
            }
        }
        return s.substr(i);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */

