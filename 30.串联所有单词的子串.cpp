/*
 * @lc app=leetcode.cn id=30 lang=cpp
 * @lcpr version=21909
 *
 * [30] 串联所有单词的子串
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), m = words.size(), w = words[0].size();

        unordered_map<string, int> tot;
        for (auto& word : words) tot[word]++;

        for (int i = 0; i < w; i++) {
            int cnt = 0;
            unordered_map<string, int> wd;
            for (int j = i; j + w <= n; j += w) {
                if (i <= j - w * m) {
                    auto word = s.substr(j - w * m, w);
                    wd[word]--;
                    if (wd[word] < tot[word]) cnt--;
                }
                auto word = s.substr(j, w);
                wd[word]++;
                if (wd[word] <= tot[word]) cnt++;
                if (cnt == m) res.push_back(j - (m - 1) * w);
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "barfoothefoobarman"\n["foo","bar"]\n
// @lcpr case=end

// @lcpr case=start
// "wordgoodgoodgoodbestword"\n["word","good","best","word"]\n
// @lcpr case=end

// @lcpr case=start
// "barfoofoobarthefoobarman"\n["bar","foo","the"]\n
// @lcpr case=end

 */
