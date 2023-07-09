/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=21909
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
        for (int i = 0, j = 0; s[i]; i++) {
            char c = s[i];
            map[c]++;
            while (map[c] > 1) map[s[j++]]--;
            res = max(res, i - j + 1);
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
