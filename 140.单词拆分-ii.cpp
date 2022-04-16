/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    unordered_set<string> set;
    vector<bool> f;
    vector<string> res;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto& word: wordDict) set.insert(word);

        int n = s.size();
        f = vector<bool>(n + 1);
        f[n] = true;

        // 预处理，以便于在暴搜时进行优化
        // f[i]: s[i~n)可以用dict中的词组成
        for (int i = n; i >= 0; i -- )
            for (int j = 0; j < i; j ++ )
                f[j] = f[j] || set.count(s.substr(j, i - j)) && f[i];

        dfs(0, s, "");
        return res;
    }

    void dfs(int u, string& s, string path) {
        if (u == s.size()) {
            path.pop_back();
            res.push_back(path);
            return;
        }

        for (int i = u; i < s.size(); i ++ )
            if (set.count(s.substr(u, i - u + 1)) && f[i + 1])
                dfs(i + 1, s, path + s.substr(u, i - u + 1) + ' ');
    }
};
// @lc code=end
