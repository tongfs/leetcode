/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        // return ss(s);
        // return tow_point(s);
        return retraverse(s);
    }

    // 解法一：用stringstream
    int ss(string s) {
        stringstream ssin(s);
        int res = 0;
        string word;
        while (ssin >> word) res = word.size();
        return res;
    }

    // 解法二：双指针
    int tow_point(string s) {
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); i = j) {
            while (s[i] == ' ') i ++ ;
            if (i == s.size()) break;
            j = i;
            while (s[j] != ' ' && s[j] != 0) j ++ ;
            res = j - i;
        }
        return res;
    }

    // 解法三：倒着遍历
    int retraverse(string s) {
        for (int i = s.size() - 1, j; i >= 0; i -- ) {
            if (s[i] == ' ') continue;
            j = i - 1;
            while (j >= 0 && s[j] != ' ') j -- ;
            return i - j;
        }
        return 0;
    }
};
// @lc code=end

