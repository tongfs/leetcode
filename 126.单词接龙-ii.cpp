/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    // 转换为图的最短路，边权都是1，可以用BFS进行建图，并求出起点到每个点的最短距离
    // 之后用DFS进行暴搜

    string beginWord;
    queue<string> q;
    unordered_set<string> S;
    unordered_map<string, int> dist;    // dist[i]: 起点到i点的最短距离
    vector<string> path;
    vector<vector<string>> res;

    vector<vector<string>> findLadders(string _beginWord, string endWord, vector<string>& wordList) {
        beginWord = _beginWord;
        for (auto& word : wordList) S.insert(word);

        q.push(beginWord);
        dist[beginWord] = 0;

        bool flag = false;
        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (int i = 0; i < t.size(); i ++ ) {
                auto s = t;
                for (char j = 'a'; j <= 'z'; j ++ ) {
                    s[i] = j;
                    if (S.count(s) && !dist.count(s)) {
                        dist[s] = dist[t] + 1;
                        if (s == endWord) {
                            flag = true;
                            break;
                        }
                        q.push(s);
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }

        if (!dist.count(endWord)) return res;

        path.push_back(endWord);
        dfs(endWord);

        return res;
    }

    void dfs(string t) {
        if (t == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (int i = 0; i < t.size(); i ++ ) {
            auto s = t;
            for (char j = 'a'; j <= 'z'; j ++ ) {
                s[i] = j;
                if (dist.count(s) && dist[t] == dist[s] + 1) {
                    path.push_back(s);
                    dfs(s);
                    path.pop_back();
                }
            }
        }
    }
};
// @lc code=end

