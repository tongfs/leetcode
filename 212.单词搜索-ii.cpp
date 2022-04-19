/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    struct TrieNode {
        int id = -1;
        TrieNode* son[26];
    }*root;
    
    int n, m;
    vector<vector<char>> g;
    unordered_set<int> set;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        g = board;
        n = g.size(), m = g[0].size();
        root = new TrieNode();

        for (int i = 0; i < words.size(); i ++ ) insert(words[i], i);

        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                int u = g[i][j] - 'a';
                if (root->son[u])
                    dfs(i, j, root->son[u]);
            }
        }
  
        vector<string> res;
        for (auto i: set) res.push_back(words[i]);
        return res;
    }

    void insert(string& word, int id) {
        auto p = root;
        for (auto c: word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new TrieNode();
            p = p->son[u];
        }
        p->id = id;
    }

    void dfs(int x, int y, TrieNode* p) {
        if (p->id != -1) set.insert(p->id);

        auto t = g[x][y];
        g[x][y] = '.';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] != '.') {
                int u = g[a][b] - 'a';
                if (p->son[u]) dfs(a, b, p->son[u]);
            }
        }
        g[x][y] = t;
    }
};
// @lc code=end

