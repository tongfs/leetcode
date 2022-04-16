/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        typedef unsigned long long ULL;
        const int P = 131;

        unordered_set<ULL> set;
        for (auto& word: wordDict) {
            ULL h = 0;
            for (auto c: word) h = h * P + c;
            set.insert(h);
        } 

        int n = s.size();
        s = ' ' + s;
        vector<bool> f(n + 1);
        
        f[0] = true;
        for (int i = 1; i <= n; i ++ ) {
            if (f[i - 1]) {
                ULL h = 0;
                for (int j = i; j <= n; j ++ ) {
                    h = h * P + s[j];
                    if (set.count(h)) f[j] = true;
                }
            }
        }

        return f[n];
    }
};
// @lc code=end

