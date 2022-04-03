/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        vector<int> ne(m + 1);
        haystack = ' ' + haystack;
        needle = ' ' + needle;

        for (int i = 2, j = 0; i <= m; i ++ ) {
            while (j && needle[i] != needle[j + 1]) j = ne[j];
            if (needle[i] == needle[j + 1]) j ++ ;
            ne[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i ++ ) {
            while (j && haystack[i] != needle[j + 1]) j = ne[j];
            if (haystack[i] == needle[j + 1]) j ++ ;
            if (j == m) return i - j;
        }

        return -1;
    }
};
// @lc code=end

