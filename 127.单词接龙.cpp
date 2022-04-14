/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> S;
        for (auto& word : wordList) S.insert(word);
        
        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        queue<string> q;
        q.push(beginWord);
        
        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (int i = 0; i < t.size(); i ++ ) {
                auto s = t;
                for (char j = 'a'; j <= 'z'; j ++ ) {
                    s[i] = j;
                    if (S.count(s) && !dist.count(s)) {
                        dist[s] = dist[t] + 1;
                        if (s == endWord) return dist[s] + 1;
                        q.push(s);
                    }
                }
            }
        }

        return 0;
    }
};
// @lc code=end

