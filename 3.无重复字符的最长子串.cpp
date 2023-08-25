/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=21910
 *
 * [3] 无重复字符的最长子串
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            map[s[j]]++;
            while (map[s[j]] > 1) map[s[i++]]--;
            res = max(res, j - i + 1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

