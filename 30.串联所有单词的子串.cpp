/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), m = words.size(), w = words[0].size();

        unordered_map<string, int> tot;
        for (auto& word : words) tot[word] ++ ;

        for (int i = 0; i < w; i ++ ) {
            int cnt = 0;
            unordered_map<string, int> wind;
            for (int j = i; j + w <= n; j += w) {
                if (i <= j - w * m) {
                    auto word = s.substr(j - w * m, w);
                    wind[word] -- ;
                    if (wind[word] < tot[word]) cnt -- ;
                }
                auto word = s.substr(j, w);
                wind[word] ++ ;
                if (wind[word] <= tot[word]) cnt ++ ;
                if (cnt == m) res.push_back(j - (m - 1) * w);
            }
        }

        return res;
    }
};
// @lc code=end

