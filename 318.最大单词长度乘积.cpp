/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> st;
        for (auto word: words) {
            int t = 0;
            for (auto c: word) {
                t |= 1 << c - 'a';
            }
            st.push_back(t);
        }

        int res = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = i + 1; j < n; j ++ )
                if ((st[i] & st[j]) == 0)
                    res = max(res, (int)(words[i].size() * words[j].size()));
        return res;
    }
};
// @lc code=end

