/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=21909
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<int> ne(m + 1);

        for (int i = 2, j = 0; i <= m; i++) {
            while (j && p[i] != p[j + 1]) j = ne[j];
            if (p[i] == p[j + 1]) j++;
            ne[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && s[i] != p[j + 1]) j = ne[j];
            if (s[i] == p[j + 1]) j++;
            if (j == m) return i - m;
        }

        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */
