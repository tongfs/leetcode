/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

#include "mylib.h"

// @lc code=start
class Trie {
public:
    // 解法一：结构体
    struct TrieNode {
        bool is_end;
        TrieNode* son[26];
    }*root;
    
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        auto p = root;
        for (auto c: word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new TrieNode();
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto c: word) {
            int u = c - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
        }
        return p->is_end;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c: prefix) {
            int u = c - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
        }
        return true;
    }


    // 解法二：静态链表实现
    /*
    int son[100000][26] = {0}, idx = 1;
    bool st[100000] = {0};

    Trie() {

    }
    
    void insert(string word) {
        int p = 0;
        for (int i = 0; word[i]; i ++ ) {
            int u = word[i] - 'a';
            if (!son[p][u]) son[p][u] = idx ++ ;
            p = son[p][u];
        }
        st[p] = true;
    }
    
    bool search(string word) {
        int p = 0;
        for (int i = 0; word[i]; i ++ ) {
            int u = word[i] - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
        }
        return st[p];
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for (int i = 0; prefix[i]; i ++ ) {
            int u = prefix[i] - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
        }
        return true;
    } */
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

