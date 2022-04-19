/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

#include "mylib.h"

// @lc code=start
class WordDictionary {
public:
    struct TrieNode {
        bool is_end;
        TrieNode* son[26];
        TrieNode() {
            is_end = false;
            for (int i = 0; i < 26; i ++ ) son[i] = nullptr;
        }
    }*root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto p = root;
        for (auto c: word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new TrieNode();
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);     
    }

    bool dfs(string& word, int k, TrieNode* p) {
        if (k == word.size()) return p->is_end;

        char c = word[k];
        if (c == '.') {
            for (int i = 0; i < 26; i ++ )
                if (p->son[i] && dfs(word, k + 1, p->son[i]))
                    return true;
        } else {
            int u = c - 'a';
            if (p->son[u] && dfs(word, k + 1, p->son[u])) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

